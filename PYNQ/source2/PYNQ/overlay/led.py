from pynq import Overlay
ol=Overlay("led.bit")
ol.download()
gpio=ol.axi_gpio_0
while(1):
    gpio.write(0,int(input("Led Output Value:")));
