# cc-sort-with-rev
A project based on cyancore software framework

To run this example, follow the below commands
```
$ git clone https://github.com/VisorFolks/cyancore.git               # Clone cyancore repo
$ make get_avr_tc       # Use correct command for fetching toolchain, this is just for illustration purpose
# copy this folder into cyancore/projects
$ make sort-with-rev
```

To build and run the example on ubutnu terminal
```
$ cd sort_with_rev
$ make app
$ ./app
```

Flash the binary on target using respective programmer.

Below is the demo running on atmega328p (Arduino Uno)

![image](./img/cc-sort-with-rev.png)
