include ./Makefile.rule
DEPS = 
dirs := $(DEPS) app

all: $(DEPS) ct

clean:
	$(foreach N,$(dirs), make clean -C $(N);)
$(DEPS):
	make all -C $@
ct:
	make all -C app
run:
	./app/test

.PHONY: all clean $(DEPS) ct run

