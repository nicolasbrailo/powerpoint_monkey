all: main.pdf

# Search each code file to format and include
CODE_FILES:=$(shell ls code/|egrep -v '.tex$ |.aux$ ' )
CODE_FILES_DEP:=$(addprefix code/, $(CODE_FILES))
CODE_FILES_TGT:=$(addsuffix .tex, $(basename $(CODE_FILES_DEP)))
# Build code frame
# (This is a hack to make it work if make'ing twice.. TODO: Fix
code_frames: code_clean $(CODE_FILES_TGT) 
code/%.tex: code/%.*
	pygmentize -f latex -O style='border=#000000,colorful,linenos=1' $< > $@

main.pdf: code_frames *.tex
	pdflatex main.tex && pdflatex main.tex 

.PHONY: run clean edit
edit: 
	gvim -S vim.sess

run: main.pdf
	evince main.pdf &

clean: code_clean
	@# for each .tex file, remove the extension
	@# 		and delete its generated files
	@for PART in $(shell ls *.tex| sed 's:.tex::g'); do \
		echo "*.out *.nav *.aux *.toc *.log *.snm *.pdf *.vrb" | \
			sed "s:*:$$PART:g" | xargs rm -f; \
	done
	@# Clean up the included code files too

code_clean:
	@rm -f $(CODE_FILES_TGT) code/*.aux

