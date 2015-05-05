PROBNAME = add
CXX_FLAGS += -std=c++11 -O2 -Wall -static

INFO_COLOR = \033[32;1m
NO_COLOR = \033[0m

.PHONY: all pack config input output testdata judge attachment clean solution

define show_target
@echo -e "$(INFO_COLOR)# $@$(NO_COLOR)"
endef

all: generator input output testdata solution config judge attachment

pack: testdata config judge attachment

generator: generator.cpp
	$(show_target)
	$(CXX) $(CXX_FLAGS) $^ -o $@

config:
	$(show_target)
	cp config.yaml ../config.yaml

input: generator
	$(show_target)
	$(RM) testdata/*
	./generator 2 sample
	./generator 3 under_1e4
	./generator 5 under_1e9

output: sol-shik-cpp input
	$(show_target)
	for f in testdata/*.in; do \
		echo "./$< < $$f > $${f%.in}.out"; \
		./$< < $$f > $${f%.in}.out; \
	done

testdata:
	$(show_target)
	$(RM) ../testdata/*
	cp testdata/* ../testdata

judge:
	$(show_target)
	$(RM) ../judge/*
	mkdir -p ../judge
	cp $(PROBNAME).h grader.c grader.cpp grader.pas ../judge

attachment:
	$(show_target)
	$(RM) -f ../attachment/*
	mkdir -p ../attachment
	cp $(PROBNAME).c $(PROBNAME).cpp $(PROBNAME).pas ../attachment
	cp $(PROBNAME).h grader.c grader.cpp grader.pas ../attachment
	cp compile_c.sh compile_cpp.sh compile_pas.sh ../attachment
	cp testdata/sample*.in testdata/sample*.out ../attachment

clean:
	$(RM) generator $(PROBNAME)
	$(RM) $(shell find sol-* -perm /111)
	$(RM) -r testdata

solution: $(subst .,-,$(wildcard sol-*))

$(subst .c,-c,%.c): %.c compile_c.sh grader.c $(PROBNAME).h
	$(show_target)
	mkdir -p build
	cp $^ build
	mv build/$< build/$(PROBNAME).c
	cd build; ./compile_c.sh
	cp build/$(PROBNAME) $@
	rm -rf build

$(subst .cpp,-cpp,%.cpp): %.cpp compile_cpp.sh grader.cpp $(PROBNAME).h
	$(show_target)
	mkdir -p build
	cp $^ build
	mv build/$< build/$(PROBNAME).cpp
	cd build; ./compile_cpp.sh
	cp build/$(PROBNAME) $@
	rm -rf build

$(subst .pas,-pas,%.pas): %.pas compile_pas.sh grader.pas
	$(show_target)
	mkdir -p build
	cp $^ build
	mv build/$< build/$(PROBNAME).pas
	cd build; ./compile_pas.sh
	cp build/$(PROBNAME) $@
	rm -rf build
