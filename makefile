BIN_EP1SH = ep1sh
SRCS_EP1SH = $(wildcard src/ep1sh/*.c) $(wildcard src/*.c)

INCS = -Isrc/
LIBS = -lreadline

CFLAGS = $(INCS) -c -g -Wall -pedantic
LDFLAGS = $(LIBS)
OUTFLAG = -o
INFLAG =

CC = gcc
DEPGEN = gcc $(INCS) -MM -MP -MT $(patsubst %$(SRCEXT),%$(OBJEXT),$<)
RM = rm -f
TOUCH = touch

OBJEXT = .o
DEPEXT = .d
SRCEXT = .c
OBJS_EP1SH = $(SRCS_EP1SH:$(SRCEXT)=$(OBJEXT))
DEPS = $(SRCS_EP1:$(SRCEXT)=$(DEPEXT)) $(SRCS_EP1SH:$(SRCEXT)=$(DEPEXT))

all: $(BIN_EP1SH)

$(BIN_EP1SH): $(OBJS_EP1SH)
	$(CC) $(LDFLAGS) $(INFLAG)$^ $(OUTFLAG)$@

clean: clean_ep1sh

clean_ep1sh:
	$(RM) $(BIN_EP1SH) $(OBJS_EP1SH) $(DEPS)

%$(OBJEXT): %$(SRCEXT)
	$(DEPGEN) $< $(OUTFLAG)$(patsubst %$(OBJEXT),%$(DEPEXT),$@)
	$(CC) $(CFLAGS) $(INFLAG)$< $(OUTFLAG)$@

%$(DEPEXT): %$(SRCEXT)
	@$(TOUCH) $@

-include $(DEPS)
