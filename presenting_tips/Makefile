all: main.pdf

main.pdf: main.tex
	pdflatex main.tex && pdflatex main.tex 

.PHONY: run clean

run: main.pdf
	evince main.pdf &

clean:
	find|grep main|grep -v tex|xargs rm
