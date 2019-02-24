# Atmega32 Fuses
A fuse is enabled when set to 0, 1 means un-programmed.

|  Name   | High fuse byte | Default |                                                                    |
|---------|----------------|---------|--------------------------------------------------------------------|
| OCDEN   | 7              | 1       | On Chip Debugging Enabled                                          |
| JTAGEN  | 6              | 0       | JTAG(Joined Test Action Group) Enabled                             |
| SPIEN   | 5              | 0       | Serial Programming Interface Enabled                               |
| WDTON   | 4              | 1       | Watchdog Timer Enabled                                             |
| EESAVE  | 3              | 1       | EEPROM (Electrically Erasable Programmable Read-Only Memory ) save |
| BOOTSZ1 | 2              | 0       | Boot Size bit 1                                                    |
| BOOTSZ0 | 1              | 0       | Boot Size bit 0                                                    |
| BOOTRST | 0              | 1       | Boot Reset                                                         |

|  Name   | Low fuse byte | Default |                     |
|---------|---------------|---------|---------------------|
| OKDIV8  | 7             | 0       | Clock Divided by 8  |
| CKOUT   | 6             | 1       | Clock Out           |
| SUT1    | 5             | 1       | Start Up Time bit 1 |
| SUT0    | 4             | 0       | Start Up Time bit 0 |
| CKSEL 3 | 3             | 0       | Clock Select bit 3  |
| CKSEL 2 | 2             | 0       | Clock Select bit 2  |
| CKSEL 1 | 1             | 1       | Clock Select bit 1  |
| CKSEL 0 | 0             | 0       | Clock Select bit 0  |


## Fuse bit (Low) settings

### On Chip Debugging Enabled

### JTAG Enabled

### SPI Enabled

### Watchdog Timer Enabled

### EEPROM Save

### Boot Size bit 1 & 0

### Boot Reset

## Fuse bit (High) settings

### Clock Divided by 8

### Clock Out

### Start Up Time bit 1 & 0

### Clock Select bit 3, 2, 1 & 0



