<div align=center>
<img src="/doc/image/logo.png"/>
</div>

## LibDriver DS18B20

[English](/README.md) | [ 简体中文](/README_CN.md)

The DS18B20 digital thermometer provides 9-bit to 12-bit Celsius temperature measurements and has an alarm function with nonvolatile user-programmable upper and lower trigger points. The DS18B20 communicates over a 1-Wire bus that by definition requires only one data line (and ground) for communication with a central microprocessor.In addition, the DS18B20 can derive power directly from the data line (“parasite power”), eliminating the need for an external power supply.Each DS18B20 has a unique 64-bit serial code, which allows multiple DS18B20s to function on the same 1-Wire bus. Thus, it is simple to use one microprocessor to control many DS18B20s distributed over a large area.Applications that can benefit from this feature include HVAC environmental controls, temperature monitoring systems inside buildings, equipment, or machinery, and process monitoring and control systems.

Libdriver DS18B20 is a full function DS18B20 driver launched by LibDriver. It provides the functions of temperature reading, ROM matching temperature reading, alarm reading and searching ROM function.

### Table of Contents

  - [Instruction](#Instruction)
  - [Install](#Install)
  - [Usage](#Usage)
    - [example basic](#example-basic)
    - [example match](#example-match)
    - [example alarm](#example-alarm)
    - [example search](#example-search)
  - [Document](#Document)
  - [Contributing](#Contributing)
  - [License](#License)
  - [Contact Us](#Contact-Us)

### Instruction

/src includes LibDriver DS18B20 source files.

/interface includes LibDriver DS18B20 onewire platform independent template。

/test includes LibDriver DS18B20 driver test code and this code can test the chip necessary function simply。

/example includes LibDriver DS18B20 sample code.

/doc includes LibDriver DS18B20 offline document.

/datasheet includes DS18B20 datasheet。

/project includes the common Linux and MCU development board sample code. All projects use the shell script to debug the driver and the detail instruction can be found in each project's README.md.

### Install

Reference /interface onewire platform independent template and finish your platform onewire driver.

Add /src, /interface and /example to your project.

### Usage

#### example basic

```C
uint8_t res;
uint8_t i;
float temperature;

res = ds18b20_basic_init();
if (res)
{
    return 1;
}

...

for (i = 0; i < 3; i++)
{
    delay_ms(2000);
    res = ds18b20_basic_read((float *)&temperature);
    if (res)
    {
        ds18b20_basic_deinit();

        return 1;
    }
    ds18b20_interface_debug_print("ds18b20: temperature is %0.2fC.\n", temperature);
    
    ...
    
}

...

ds18b20_basic_deinit();

return 0;
```

#### example match

```C
uint8_t res;
uint8_t i;
float temperature;
uint8_t rom[8];

res = ds18b20_match_init();
if (res)
{
    return 1;
}

...

for (i = 0; i < 3; i++)
{
    delay_ms(2000);
    res = ds18b20_match_read((uint8_t *)rom, (float *)&temperature);
    if (res)
    {
        ds18b20_match_deinit();

        return 1;
    }
    ds18b20_interface_debug_print("ds18b20: temperature is %0.2fC.\n", temperature);
    
    ...
    
}

...

ds18b20_match_deinit();

return 0;
```

#### example alarm

```C
uint8_t res;
uint8_t rom[8][8];
uint8_t num;
uint8_t i, j;

res = ds18b20_alarm_init();
if (res)
{
    return 1;
}

...

num = 8;
res = ds18b20_alarm_search((uint8_t (*)[8])rom, (uint8_t *)&num);
if (res)
{
    ds18b20_alarm_deinit();

    return 1;
}
ds18b20_interface_debug_print("ds18b20: find %d alarm rom(s).\n", num);

...

for (i = 0; i < num; i++)
{
    for (j = 0; j < 8; j++)
    {
        ds18b20_interface_debug_print("%02X ", rom[i][j]);
    }
    ds18b20_interface_debug_print(".\n");
    
    ...
    
}

...

ds18b20_alarm_deinit();

return 0;
```

#### example search

```C
uint8_t res, i, j;
uint8_t rom[8][8];
uint8_t num;

res = ds18b20_search_init();
if (res)
{
    return 1;
}

...

num = 8;
res = ds18b20_search((uint8_t (*)[8])rom, (uint8_t *)&num);
if (res)
{
    ds18b20_search_deinit();

    return 1;
}
ds18b20_interface_debug_print("ds18b20: find %d rom(s).\n", num);

...

for (i = 0; i < num; i++)
{
    uart1_print("ds18b20: %d/%d is ", (uint32_t)(i+1), (uint32_t)num);
    for (j = 0; j < 8; j++)
    {
        ds18b20_interface_debug_print("%02X ", rom[i][j]);
    }
    ds18b20_interface_debug_print(".\n");
    
    ...
    
}

...
    
ds18b20_search_deinit();

return 0;
```

### Document

Online documents: https://www.libdriver.com/docs/ds18b20/index.html

Offline documents: /doc/html/index.html

### Contributing

Please sent an e-mail to lishifenging@outlook.com

### License

Copyright (C) LibDriver 2015-2021 All rights reserved 



The MIT License (MIT) 



Permission is hereby granted, free of charge, to any person obtaining a copy

of this software and associated documentation files (the "Software"), to deal

in the Software without restriction, including without limitation the rights

to use, copy, modify, merge, publish, distribute, sublicense, and/or sell

copies of the Software, and to permit persons to whom the Software is

furnished to do so, subject to the following conditions: 



The above copyright notice and this permission notice shall be included in all

copies or substantial portions of the Software. 



THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR

IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,

FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE

AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER

LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,

OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE

SOFTWARE. 

### Contact Us

Please sent an e-mail to lishifenging@outlook.com