.global WriteWS2812

WriteWS2812:
    # x10 = colors
    # x11 = size
    # x12 = port
    # x13 = pin
    mv x14, x11
    add x14, x11, x14
    add x14, x11, x14
    add x14, x11, x14
    mv x11, x14

    # x14 = led index
    mv x14, x0
    byte_loop_start:
        # x15 = offset + colors
        add x15, x10, x14
        # x15 = *x15
        lw x15, 0(x15)

        # x5 = current bit index as bitmask
        li x5, 1
        slli x5, x5, 23
        bit_loop_start:
            sw x13, 16(x12)

            # x7 = current bit value
            and x7, x5, x15
            srli x5, x5, 1
            bne x7, x0, write_one
            write_zero:
            nop
            nop
            nop
            nop
            sw x13, 20(x12)
            nop
            nop
            nop
            beq x5, x0, bit_loop_end
            nop
            nop
            nop
            nop
            nop
            nop
            nop
            nop
            j write_end
            write_one:
            nop
            nop
            nop
            nop
            nop
            nop
            nop
            nop
            beq x5, x0, bit_loop_end
            nop
            nop
            sw x13, 20(x12)
            nop
            nop
            nop
            nop
            nop
            nop

            write_end:

            bne x5, x0, bit_loop_start
        bit_loop_end:
        sw x13, 20(x12)

        add x14, x14, 4
        bne x11, x14, byte_loop_start
    byte_loop_end:

    ret
