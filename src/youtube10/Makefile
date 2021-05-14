# Makefile
SRC    :=bootx64.asm

all: FASM

FASM:
	fasm $(SRC) BOOTX64.EFI

clean:
	@echo "Cleaning files...."
	rm -f *.EFI
	@echo "Done."
