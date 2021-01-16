import time
import numpy as np

from pyzmodlib import ZMODADC1410

import matplotlib
matplotlib.use('Agg')
# %matplotlib inline

import matplotlib.pyplot as plt


TRANSFER_LEN = 0x400
IIC_BASE_ADDR = 0xE0005000
ZMOD_IRQ = 61

ADC_BASE_ADDR = 0x43C00000
ADC_DMA_BASE_ADDR = 0x40400000
ADC_FLASH_ADDR = 0x30
ADC_DMA_IRQ = 62

def writeADCData(adcZmod, filename, acqBuffer, channel, gain, length):
    '''
    Format data contained in the buffer and writes it to a file and to the standard output.
    The file is overwritten any time the function is called.
     @param filename - the file name to contain the acquisition formatted data
     @param acqBuffer - the buffer containing acquired data
     @param channel - the channel where samples were acquired
     @param gain - the gain for the channel
     @param length	- the buffer length to be used
    '''

    ret = []
    with open(filename, 'w') as f:
        print("Channel, Time\n", file=f)
        
        for i in range(length):
            time_formatted = ""
            if (i < 100):
                time_formatted = str(i*10) + "ns";
            else:
                time_formatted = str((float(i))/100.0) + "us";
            valCh = adcZmod.signed_channel_data(channel, adcZmod.get_data(acqBuffer, i))
            val = adcZmod.get_volt_from_signed_raw(valCh, gain)
            val_formatted = str(1000.0*val) + "mV"
            print("{}, {}".format(time_formatted, val_formatted), file=f)
            print("{}, {}".format(time_formatted, val_formatted))
            ret.append(val)
    return ret

def adcDemo(adcZmod, channel, gain, length, repetition=1):
    '''
    Performs (repeatedly) un-triggered acquisitions and writes the data to a file and to the standard output.
    The file only contains the content of one acquisition, as it is overwritten.
     @param channel - the channel where samples were acquired
     @param gain - the gain for the channel
    @param length	- the buffer length to be used
    '''
    acqBuffer = 0
    adcZmod.set_gain(channel, gain)
    ret = []
    for i in range(repetition):
        acqBuffer = adcZmod.alloc_channels_buffer(length)
        adcZmod.acquire_immediate_polling(acqBuffer, length)
        ret = writeADCData(adcZmod, "buffer_data.csv", acqBuffer, channel, gain, length)
        adcZmod.free_channels_buffer(acqBuffer, length);
        time.sleep(2)
    return ret

def main():
    print("ZmodADC1410 Demo")
    # channel CH1
    # gain    LOW - Corresponds to HIGH input Range
    # length  0x400
    adcZmod = ZMODADC1410(ADC_BASE_ADDR, ADC_DMA_BASE_ADDR, IIC_BASE_ADDR, ADC_FLASH_ADDR, ZMOD_IRQ, ADC_DMA_IRQ)
    dat = adcDemo(adcZmod, 0, 0, TRANSFER_LEN);
    print('read data done')
    print(dat)
    plt.plot(dat)
    print('plot done')
    plt.savefig('buffer_data.png')


if __name__ == "__main__":
    main()
