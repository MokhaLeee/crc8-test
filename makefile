target := crc-test

all: $(target)

CC := gcc
src-y := src/main.c src/crc8.c

crc-test: $(src-y)
	@echo [CC]	$^
	@$(CC) $^ -o $@

clean:
	@rm -f $(target)
	@echo all cleaned...
