.PRECIOUS: *.tex
.PHONY: clean all cleanall

TEX=xelatex
PANDOCARG=-V theme=Berlin -V fonttheme=professionalfonts -V listings -V tables -V graphics -V url -V toc --slide-level=3
REQUIRE=Makefile template.tex beamer-header.tex

TARGET=slide.pdf
ALL=$(TARGET)

target: $(TARGET)
all: $(ALL)

slide.md: ../README.md
	cp ../README.md $@

%.pdf: %.tex $(REQUIRE)
	$(TEX) -synctex=1 -interaction=nonstopmode $< > /dev/null
	$(TEX) -synctex=1 -interaction=nonstopmode $< > /dev/null


%.tex: %.md $(REQUIRE)
	pandoc -S -R -f markdown+definition_lists -t beamer -s $(PANDOCARG) -H ./beamer-header.tex --template=./template.tex $< -o $@

clean:
	rm -f *.synctex.gz *.aux *.log *.toc *.snm *.nav *.out *.vrb $(ALL:.pdf=.tex) *.md
cleanall: clean
	rm -f *.pdf
