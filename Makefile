OPTIONS = -Werror -Wall -Wextra -pedantic -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-promo -Wstrict-overflow=5 -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option
ABANDONED = -Wlogical-op -Wnoexcept -Wstrict-null-sentinel
SRC = p.c
mymake: $(SRC)
	gcc -o r $(SRC) $(OPTIONS)

clean:
	rm r

run: r
	@./r

inf:
	./inf.sh

