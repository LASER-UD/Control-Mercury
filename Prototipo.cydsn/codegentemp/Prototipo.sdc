# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\nikod\Documents\PSoC Creator\Control-Mercury\Prototipo.cydsn\Prototipo.cyprj
# Date: Fri, 14 Jun 2019 23:49:10 GMT
#set_units -time ns
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_generated_clock -name {CLK1} -source [get_pins {ClockBlock/clk_sync}] -edges {1 11 21} -nominal_period 416.66666666666663 [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/clk_sync}] -edges {1 11 21} -nominal_period 416.66666666666663 [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {ADC_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 21 41} -nominal_period 833.33333333333326 [list [get_pins {ClockBlock/aclk_glb_0}]]
create_generated_clock -name {UART_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 313 627} [list [get_pins {ClockBlock/dclk_glb_2}]]
create_generated_clock -name {CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 1201 2401} [list [get_pins {ClockBlock/dclk_glb_3}]]


# Component constraints for C:\Users\nikod\Documents\PSoC Creator\Control-Mercury\Prototipo.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\nikod\Documents\PSoC Creator\Control-Mercury\Prototipo.cydsn\Prototipo.cyprj
# Date: Fri, 14 Jun 2019 23:48:57 GMT
