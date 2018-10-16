import smbus
# from smbus2 import SMBus

import time

# for RPI version 1, use “bus = smbus.SMBus(0)”
bus = smbus.SMBus(1)

# This is the address we setup in the Arduino Program
address = 0x04

cmd_calibrate = 1
cmd_move_h = 2
cmd_move_m = 3
cmd_move_both = 4
cmd_sleep = 5

dir_cw = 0
dir_ccw = 1

def writeNumber(value):
    bus.write_byte(
        address,
        int(value))
    # bus.write_byte_data(address, 0, value)
    return -1

def write2bytes(number):
    #bus.write_block_data(address, 255, [number, number])
    print(number >> 8)
    print(number & 0xff)
    bus.write_block_data(address, 255, [number >> 8, number & 0xff])
    #
    # writeNumber(number >> 8)
    # writeNumber(number & 8)


def readNumber():
    number = bus.read_byte(address)
    # number = bus.read_byte_data(address, 1)
    return number

# state = 0;
while True:
    # var = input("Enter 1 – 9: ")
    # if not var:
    #     continue
    num = 0
    num += pow(2, 15) + 3
    print(num)

    # writeNumber(num)
    write2bytes(num)
    break

    var = 1
 # state == 0 ? 1 : 1

    writeNumber(var)
    print("RPI: Hi Arduino, I sent you ", var)
    # sleep one second
    # time.sleep(1)

    number = readNumber()
    print("Arduino: Hey RPI, I received a digit ", number)
    print
    time.sleep(1)
