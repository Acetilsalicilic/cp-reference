latex_command := lualatex
source := reference.tex
final := reference.pdf
build_dir := ./build

$(final): $(source)
	mkdir -p $(build_dir)

	$(latex_command) --output-directory=$(build_dir) $(source)

	mv $(build_dir)/$(final) .
	rm -rf $(build_dir)
