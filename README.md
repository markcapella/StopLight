# StopLight
    
!['StopLightIcon'](https://github.com/markcapella/StopLight/blob/main/StopLight.png)
!['StopLight'](https://github.com/markcapella/StopLight/blob/main/screenshot.png)

    
## Description

>     StopLight 🚦 is an LXQT Panel plugin Widget that monitors your base SSD
> or hard drive, and provides an indicator that reports available space in
> Green, Yellow or Red warning colors. Warning levels & more are configurable.
>
>    Running an SSD completely full can cause surprisingly serious problems
> on Linux, although the SSD itself usually isn't physically damaged.
>
>    Always run the StopLight! 😎️
>
>    Once the filesystem has no blocks available, operations start
> returning no space left on device and that can cascade.
>
>    Eventually you can wind up with a system that boots but behaves
> very strangely, or in worse cases has trouble completing boot.
>
>    Protect against login lock-out, & install StopLight today !

## List of Horribles.

* Logs need to append to files.
* Temporary files go into /tmp, /var/tmp, etc.
* Package managers need working space for downloads and unpacking.
* Databases need to write journal/WAL files.
* Browsers need cache/database space.
* Desktop applications need temporary files and state.
* The filesystem itself needs metadata/free blocks for normal operation.
* Swap may need to grow or write pages if you're using a swapfile.
* Updates can require more temporary space than the final installed size.

## Installation.

### Install Pre-reqs.

> This is automated. The build system will warn you of missing packages.

### Clone StopLight source folder.

    git clone https://github.com/markcapella/StopLight

### CD into source repo.

    cd StopLight

## Basic development.

'''bash
./startPlugin
'''
'''bash
./buildPlugin
'''
'''bash
./installPlugin
./restartPanel
'''
'''bash
./uninstallPlugin
'''
'''bash
./cleanPlugin
rm -rf ~/.config/StopLight
'''

## Usage after install.

### LXQT Desktop with lxqt-panel.

> Right click the panel and select "Manage Widgets".
>
> From the displayed Configure Panel dialog, select the right-hand
> side green Plus button "+" to open the "Add Plugins" dialog.
>
> Select StopLight from the list and click the "add Widget" button.

## Adding your own language is simple:

### Edit the three small code blocks in TranslationHelperStrings.h.

> Follow the directions in the file and re-build.

## markjamescapella@proton.me Rocks !

> Yeah I do.
>
> Always run the StopLight! 😎️
