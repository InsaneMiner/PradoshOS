#  MIT License
#
#  Copyright (c) 2021 Pradosh Company
#
#  Permission is hereby granted, free of charge, to any person obtaining a copy
#  of this software and associated documentation files (the "Software"), to deal
#  in the Software without restriction, including without limitation the rights
#  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#  copies of the Software, and to permit persons to whom the Software is
#  furnished to do so, subject to the following conditions:
#
#  The above copyright notice and this permission notice shall be included in all
#  copies or substantial portions of the Software.
#
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#  SOFTWARE.

OSNAME = PradoshOS

GNUEFI = ../gnu-efi
OVMFDIR = ../OVMFbin
LDS = kernel.ld
CC = gcc
ASMC = nasm
LD = ld

CFLAGS = -ffreestanding -fshort-wchar -mno-red-zone -fno-exceptions
ASMFLAGS =
LDFLAGS = -T $(LDS) -static -Bsymbolic -nostdlib

SRCDIR := src
OBJDIR := lib
BUILDDIR = bin
USRDIR := userland
CHKDIR := chk
DUMPDIR := dump
BOOTEFI := $(GNUEFI)/x86_64/bootloader/main.efi
BOOTX64 := $(GNUEFI)/x86_64/bootloader/bootx64.efi
BOOTIA32 := $(BUILDDIR)/bootia32.efi

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRC = $(call rwildcard,$(SRCDIR),*.cpp)
ASMSRC = $(call rwildcard,$(SRCDIR),*.asm)
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))
OBJS += $(patsubst $(SRCDIR)/%.asm, $(OBJDIR)/%_asm.o, $(ASMSRC))
DIRS = $(wildcard $(SRCDIR)/*)

kernel: $(OBJS) link


$(OBJDIR)/interrupts/interrupts.o: $(SRCDIR)/interrupts/interrupts.cpp
	@ echo "\e[1;34mCOMPILING $^\e[0m"
	@ mkdir -p $(@D)
	$(CC) -mno-red-zone -mgeneral-regs-only -ffreestanding -c $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@ echo "\e[1;34mCOMPILING $^\e[0m"
	@ mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@ echo "\e[1;34mCOMPILING $^\e[0m"
	@ mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@

$(OBJDIR)/%_asm.o: $(SRCDIR)/%.asm
	@ echo "\e[1;34mCOMPILING $^\e[0m"
	@ mkdir -p $(@D)
	$(ASMC) $(ASMFLAGS) $^ -f elf64 -o $@

cmplMulitask:
	@ echo COMPILING multitask...
	nasm -f elf32 $(SRCDIR)/mtask.asm -o $(OBJDIR)/mtask_asm.o

link:
	touch $(CHKDIR)/.obj-done
	@ echo "\e[1;34mLINKING $^\e[0m"
	$(LD) $(LDFLAGS) -o $(BUILDDIR)/kernel.elf $(OBJS)
	@touch $(CHKDIR)/.link-done

setup:
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(SRCDIR)
	@mkdir -p $(OBJDIR)
	@mkdir -p $(CHKDIR)
	@mkdir -p $(DUMPDIR)
	@touch $(CHKDIR)/.setup-done

clean:
	- rm -r lib/*

deep-clean:
	- rm -r chk/*
	clean

all: clean kernel buildimg read print

userland:
	nasm $(ASMFLAGS) src/userland/userlandASM.asm -f elf64 -o lib/userland/userlandASM.o

print:
	@ echo
	@ echo "\e[1;32m [DONE] PradoshOS compiled and builded Successfully! \e[0m"

read:
	hexdump -C bin/kernel.elf > $(DUMPDIR)/hexdump.txt
	readelf -a bin/kernel.elf > $(DUMPDIR)/ReadELF.txt
	objdump -a bin/kernel.elf > $(DUMPDIR)/objdump.txt
	objdump -f bin/kernel.elf >> $(DUMPDIR)/objdump.txt

version:
	objcopy res/version.txt -O version.o
	copy res/version.o lib/

kernelchkRIP:
	addr2line -fe bin/kernel.elf 0x000000000f0f841e

buildimg:
	qemu-img create -f raw $(BUILDDIR)/$(OSNAME).img 10M
	mformat -v PradoshOS -i $(BUILDDIR)/$(OSNAME).img ::
	mmd -i $(BUILDDIR)/$(OSNAME).img ::/EFI
	mmd -i $(BUILDDIR)/$(OSNAME).img ::/EFI/BOOT
	mmd -i $(BUILDDIR)/$(OSNAME).img ::/EFI/pradx-boot
	mmd -i $(BUILDDIR)/$(OSNAME).img ::/PradoshOS
	mmd -i $(BUILDDIR)/$(OSNAME).img ::/PradoshOS/Recovery
	mmd -i $(BUILDDIR)/$(OSNAME).img ::/syscfg
	mcopy -i $(BUILDDIR)/$(OSNAME).img $(BOOTEFI) ::/EFI/pradx-boot
	mcopy -i $(BUILDDIR)/$(OSNAME).img res/bootx64.efi ::/EFI/BOOT
	mcopy -i $(BUILDDIR)/$(OSNAME).img ../Limine/bootmgr/bootmgr.efi ::
	mcopy -i $(BUILDDIR)/$(OSNAME).img ../Limine/limine.cfg ::
	mcopy -i $(BUILDDIR)/$(OSNAME).img res/startup.nsh ::
	mcopy -i $(BUILDDIR)/$(OSNAME).img $(BUILDDIR)/kernel.elf ::
	mcopy -i $(BUILDDIR)/$(OSNAME).img res/zap-light16.psf ::
	mcopy -i $(BUILDDIR)/$(OSNAME).img res/shimx64.efi ::/PradoshOS/Recovery
	@touch $(CHKDIR)/.img-done

Check: CheckMultiboot_bootloader Checkx86_64_bootloader

CheckMultiboot_bootloader:
	@if grub-file --is-x86-multiboot $(BOOTEFI); then   echo multiboot confirmed; else   echo the file is not multiboot; fi

Checkx86_64_bootloader:
	@if grub-file --is-x86_64-efi $(BOOTEFI); then   echo File is x86_64; else   echo File is not x86_64; fi
