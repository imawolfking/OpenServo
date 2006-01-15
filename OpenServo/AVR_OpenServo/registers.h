/*
   Copyright (c) 2006, Mike Thompson <mpthompson@gmail.com>
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _OS_REGISTERS_H_
#define _OS_REGISTERS_H_ 1

//
// Defines servo control registers.
//

// TWI read/only status registers.  Writing
// values to these registers has no effect.

#define REG_DEVICE_TYPE             0x00
#define REG_DEVICE_SUBTYPE          0x01
#define REG_VERSION_MAJOR           0x02
#define REG_VERSION_MINOR           0x03
#define REG_FLAGS_HI                0x04
#define REG_FLAGS_LO                0x05
#define REG_TIMER_HI                0x06
#define REG_TIMER_LO                0x07

#define REG_POSITION_HI             0x08
#define REG_POSITION_LO             0x09
#define REG_VELOCITY_HI             0x0A
#define REG_VELOCITY_LO             0x0B
#define REG_POWER_HI                0x0C
#define REG_POWER_LO                0x0D
#define REG_PWM_CW                  0x0E
#define REG_PWM_CCW                 0x0F

// TWI read/write registers.  Writing these
// registers controls operation of the servo.

#define REG_SEEK_HI                 0x10
#define REG_SEEK_LO                 0x11
#define REG_MAXIMUM_PWM             0x12
#define REG_RESERVED_13             0x13
#define REG_RESERVED_14             0x14
#define REG_RESERVED_15             0x15
#define REG_RESERVED_16             0x16
#define REG_RESERVED_17             0x17

#define REG_RESERVED_18             0x18
#define REG_RESERVED_19             0x19
#define REG_RESERVED_1A             0x1A
#define REG_RESERVED_1B             0x1B
#define REG_RESERVED_1C             0x1C
#define REG_RESERVED_1D             0x1D
#define REG_RESERVED_1E             0x1E
#define REG_RESERVED_1F             0x1F


// TWI safe read/write registers.  These registers
// may only be written to when write enabled.

#define REG_TWI_ADDRESS             0x20
#define REG_RESERVED_21             0x21
#define REG_PID_PGAIN_HI            0x22
#define REG_PID_PGAIN_LO            0x23
#define REG_PID_DGAIN_HI            0x24
#define REG_PID_DGAIN_LO            0x25
#define REG_PID_IGAIN_HI            0x26
#define REG_PID_IGAIN_LO            0x27

#define REG_MIN_SEEK_HI             0x28
#define REG_MIN_SEEK_LO             0x29
#define REG_MAX_SEEK_HI             0x2A
#define REG_MAX_SEEK_LO             0x2B
#define REG_REVERSE_SEEK            0x2C
#define REG_RESERVED_2D             0x2D
#define REG_RESERVED_2E             0x2E
#define REG_RESERVED_2F             0x2F

#define REG_RESERVED_30             0x30
#define REG_RESERVED_31             0x31
#define REG_RESERVED_32             0x32
#define REG_RESERVED_33             0x33
#define REG_RESERVED_34             0x34
#define REG_RESERVED_35             0x35
#define REG_RESERVED_36             0x36
#define REG_RESERVED_37             0x37

#define REG_RESERVED_38             0x38
#define REG_RESERVED_39             0x39
#define REG_RESERVED_3A             0x3A
#define REG_RESERVED_3B             0x3B
#define REG_RESERVED_3C             0x3C
#define REG_RESERVED_3D             0x3D
#define REG_RESERVED_3E             0x3E
#define REG_RESERVED_3F             0x3F

//
// Define the register ranges.
//
#define MIN_RO_REGISTER             0x00
#define MAX_RO_REGISTER             0x0F
#define MIN_RW_REGISTER             0x10
#define MAX_RW_REGISTER             0x1F
#define MIN_SW_REGISTER             0x20
#define MAX_SW_REGISTER             0x3F
#define MAX_REGISTER                MAX_SW_REGISTER

//
// Define the flag register REG_FLAGS_HI and REG_FLAGS_LO bits.
//

#define FLAGS_HI_RESERVED_07        0x07
#define FLAGS_HI_RESERVED_06        0x06
#define FLAGS_HI_RESERVED_05        0x05
#define FLAGS_HI_RESERVED_04        0x04
#define FLAGS_HI_RESERVED_03        0x03
#define FLAGS_HI_RESERVED_02        0x02
#define FLAGS_HI_RESERVED_01        0x01
#define FLAGS_HI_RESERVED_00        0x00

#define FLAGS_LO_RESERVED_07        0x07
#define FLAGS_LO_RESERVED_06        0x06
#define FLAGS_LO_RESERVED_05        0x05
#define FLAGS_LO_RESERVED_04        0x04
#define FLAGS_LO_RESERVED_03        0x03
#define FLAGS_LO_RESERVED_02        0x02
#define FLAGS_LO_WRITE_ENABLED      0x01
#define FLAGS_LO_PWM_ENABLED        0x00

// Global register array.
extern uint8_t registers[MAX_REGISTER + 1];

// Register functions.

void registers_init(void);
void registers_defaults(void);

// Register in-line functions.

// Read a single byte from the registers.
inline static uint8_t registers_read_byte(uint8_t address)
{
    return registers[address];
}


// Write a single byte to the registers.
inline static void registers_write_byte(uint8_t address, uint8_t value)
{
    registers[address] = value;
}


// Read a 16-bit word from the registers.
// Interrupts are disabled during the read.
inline static uint16_t registers_read_word(uint8_t address_hi, uint8_t address_lo)
{
    uint16_t value;

    asm volatile (
        "in __tmp_reg__,__SREG__\n\t"
        "cli\n\t"
        "mov %A0,%2\n\t"
        "mov %B0,%1\n\t"
        "out __SREG__,__tmp_reg__\n\t"
        : "=r" ((uint16_t) (value)) \
        : "r" ((uint8_t) (registers[address_hi])),
          "r" ((uint8_t) (registers[address_lo]))
    );

    return value;
}


// Write a 16-bit word to the registers.
// Interrupts are disabled during the write.
inline static void registers_write_word(uint8_t address_hi, uint8_t address_lo, uint16_t value)
{
    asm volatile (
        "in __tmp_reg__,__SREG__\n\t"
        "cli\n\t"
        "mov %0,%B2\n\t"
        "mov %1,%A2\n\t"
        "out __SREG__,__tmp_reg__\n\t"
        : "=&r" ((uint8_t) (registers[address_hi])),
          "=r" ((uint8_t) (registers[address_lo]))
        : "r" ((uint16_t) (value))
    );
}


inline static void registers_write_enable(void)
{
    uint8_t flags_lo = registers_read_byte(REG_FLAGS_LO);

    // Enable PWM to the servo motor.
    registers_write_byte(REG_FLAGS_LO, flags_lo | (1<<FLAGS_LO_WRITE_ENABLED));
}


inline static void registers_write_disable(void)
{
    uint8_t flags_lo = registers_read_byte(REG_FLAGS_LO);

    // Disable PWM to the servo motor.
    registers_write_byte(REG_FLAGS_LO, flags_lo & ~(1<<FLAGS_LO_WRITE_ENABLED));
}


inline static uint8_t registers_is_write_enabled(void)
{
    return (registers_read_byte(REG_FLAGS_LO) & (1<<FLAGS_LO_WRITE_ENABLED)) ? 1 : 0;
}


inline static uint8_t registers_is_write_disabled(void)
{
    return (registers_read_byte(REG_FLAGS_LO) & (1<<FLAGS_LO_WRITE_ENABLED)) ? 0 : 1;
}


#endif // _OS_REGISTERS_H_

