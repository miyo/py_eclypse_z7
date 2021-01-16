from pyzmodlib import ZMODDAC1411

TRANSFER_LEN = 0x400
IIC_BASE_ADDR = 0xE0005000
ZMOD_IRQ = 61

DAC_BASE_ADDR = 0x43C10000
DAC_DMA_BASE_ADDR = 0x40410000
DAC_FLASH_ADDR = 0x31
DAC_DMA_IRQ = 63

def dacRampDemo(offset, amplitude, step, channel, frequencyDivider, gain):

    dacZmod = ZMODDAC1411(DAC_BASE_ADDR, DAC_DMA_BASE_ADDR, IIC_BASE_ADDR, DAC_FLASH_ADDR, DAC_DMA_IRQ)

    length = int(amplitude/step) << 2
    if (length > ((1<<14) - 1)):
        # limit the length to maximum buffer size (1<<14 - 1)
        length = ((1<<14) - 1)
        # adjust step
        step = amplitude/(length>>2)

    buf = dacZmod.alloc_channels_buffer(length)

    dacZmod.set_output_sample_frequency_divider(frequencyDivider)
    dacZmod.set_gain(channel, gain)

    i = 0;
    # ramp up
    val = -amplitude
    while(val < amplitude):
        valRaw = dacZmod.get_signed_raw_from_volt(val + offset, gain)
        valBuf = dacZmod.arrange_channel_data(channel, valRaw&0xFFFF)
        dacZmod.put_data(buf, i, valBuf)
        print(i, valBuf)
        val += step
        i += 1
        
    # ramp down
    val = amplitude
    while(val > -amplitude):
        valRaw = dacZmod.get_signed_raw_from_volt(val + offset, gain)
        valBuf = dacZmod.arrange_channel_data(channel, valRaw&0xFFFF)
        dacZmod.put_data(buf, i, valBuf)
        print(i, valBuf)
        val -= step
        i += 1

    # send data to DAC and start the instrument
    dacZmod.set_data(buf, length)
    dacZmod.start()
    dacZmod.free_channels_buffer(buf, length)

def main():
    print("ZmodDAC1411 Demo")
    # offset                   2 V
    # amplitude                3 V
    # step                     10 mV
    # channel                  A
    # Output Frequency Divider 2
    # gain                     HIGH
    dacRampDemo(2, 3, 0.01, 0, 1, 1);

if __name__ == "__main__":
    main()
