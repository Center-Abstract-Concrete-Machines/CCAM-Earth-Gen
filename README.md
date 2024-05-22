# Welcome to CCAM EARTH 

## Short Overview
EARTH is a music-making framework that affords tactile performance with hardware while leveraging the malleability of working with software. By concretizing an affordable daughter board for the seed, we intend this repository as a commons. The more who share, the more is available to people coming on board. 

## Getting Started

### Required elements: 
#### 1. A Daisy Seed Microcontroller 
Built by Electrosmith, readily available and affordable. You may buy one with pins soldered or unsoldered. Seeds come in 1mb or 65mb of RAM; generally if you working with long loops, delays, or samplers, you will want the 65mb. For sequencers, simple synthesis and other operations the 1mb is sufficient.    
#### 2. A piece of EARTH hardware
CCAM designed this to interface with the Daisy Seed Microcontroller built by ElectroSmith. The hardware is currently being open-sourced; you may have one from a CCAM workshop or the CCAM store. What we intend here is to lock in certain mappings (6 pots, 8 LEDs, 8 buttons, 2 cv ins and 2 outs, stereo audio I/O, MIDI in). 

We think the CV in/outs are the neatest part. They allow you to send continuous signals (such as LFOs, stepped pitch data, clocks, triggers, etc.) **between** EARTH modules. Please note that the CV ins are tolerant up to 3v3; that means no BOSS SQ-1, BeatStep Pro, etc. Double check the voltages of your existing gear before you try to loop it in. The Teenage Engineer pocket operator set for example will work as an input (they send up to 3 volt) but *not* as an output (they only accept up to 3v, not 3v3!). In the future we are interested in creating a voltage convertor box to go between 12v and 3v3.  

#### 3. Installed software program and dependencies   
Daisy supports code written Arduino (Daisyduino), PureData, and Max/MSP Gen~, and more. Our initial examples are written in Max/MSP Gen~ as we take inspiration and concepts from the recent text Generating Sound and Organizing Time by Graham Wakefield and Gregory Taylor, an introduction to audio synthesis through Gen~'s sample-based paradigm. We welcome other contributions however, and you may find your own software workflow with EARTH. The [Daisy Wiki](https://github.com/electro-smith/DaisyWiki/wiki) will be your friend for all "getting started" questions you might have on the software end. 

## Flashing your first EARTH
"Kronos/Kairos" is a drum machine / clock module that is a good standalone test. Note that the directory contains the JSON file Oopsy needs to correctly interpret the hardware's ins and outs (Oopsy is the MaxMSP library for flashing Gen~ code to Daisy). Check the Daisy WIKI for more complete instructions on flashing the Daisy from Oopsy.

## Contributing
The point of the repository is to share! We complete contributions from all software types. 

### Guidelines
- As a matter of course, your contribution should run on the Daisy Seed with the CCAM EARTH hardware.
- Your patch or code should be well comment and clean. No Autechre max patches please!
- If working in Gen~/Oopsy, include a JSON file with the proper mappings to Gen~ params with name `instrumentname_params` where instrument name is the name you've given to the patch.
- Regarding naming, we've chosen to riff into Daisy's terrestrial and ecological namespace. Given that CCAM borrows much from process philosophy and related schools of thought, we are also riffing into Deleuze and Guattari and so on. That's an invitation and by no means an order :)

### How-to
Fork the repository to work on your own. Create a new folder with the name of your instrument and ideally work only on that folder. When you are ready to merge, create a pull request and the maintainers will go through your code and make sure everything is gravy!





