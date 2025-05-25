# Downloads
[VMWare](https://files02.tchspt.com/down/VMware-player-17.6.3-24583834.exe)

the reason for the mulitple download links are because of location

[Linux mint](https://mirror.ette.biz/linuxmint/stable/22.1/linuxmint-22.1-cinnamon-64bit.iso) (america 1) 
[Linux mint](https://mirrors.seas.harvard.edu/linuxmint/stable/22.1/linuxmint-22.1-cinnamon-64bit.iso) (america 2)
[other locations](https://linuxmint.com/edition.php?id=319)

**WE DO NOT SUPPORT FOR ANTI-VM DETECTION BYPASS FOR OTHER THAN VMWARE!**


# 2. Setting up Virtual-Machine

Please follow the steps below to setup your VM configuration.

## Change the MAC address of your VM

Open your VM settings and select `Network Adapter` tab and open `Advanced` section.

and change the MAC address to like `00:0C:29:00:00:01`  (Avoid using address starting with `00:50`!)

## Avoid Virtaul-Machine detection from EAC

Open your VM file location and open `.vmx` file with a text editor.
And add the following lines to the end of the file.

> [!NOTE]
> Make sure you closed your VM before editing `.vmx` file.

```
hypervisor.cpuid.v0 = "FALSE"
board-id.reflectHost = "TRUE"
hw.model.reflectHost = "TRUE"
serialNumber.reflectHost = "TRUE"
smbios.reflectHost = "TRUE"
SMBIOS.noOEMStrings = "TRUE"
isolation.tools.getPtrLocation.disable = "TRUE"
isolation.tools.setPtrLocation.disable = "TRUE"
isolation.tools.setVersion.disable = "TRUE"
isolation.tools.getVersion.disable = "TRUE"
monitor_control.disable_directexec = "TRUE"
monitor_control.disable_chksimd = "TRUE"
monitor_control.disable_ntreloc = "TRUE"
monitor_control.disable_selfmod = "TRUE"
monitor_control.disable_reloc = "TRUE"
monitor_control.disable_btinout = "TRUE"
monitor_control.disable_btmemspace = "TRUE"
monitor_control.disable_btpriv = "TRUE"
monitor_control.disable_btseg = "TRUE"
monitor_control.restrict_backdoor = "TRUE"
scsi0:0.productID = "Tencent SSD"
scsi0:0.vendorID = "Tencent"
```

# 3. Prepare Linux side

## Install real linux :/
In the top left it should say something like "Install Linux Mint". click that and go through it and finish it.
if it doesnt, then you already have it. go to next step.

## Install steam
open terminal
```install flatpack - sudo apt install flatpak```
```install steam - flatpak install flathub com.valvesoftware.Steam ```
```open steam. (if it says an erorr do the following)```
```install steam devices - sudo apt install steam-devices```


## Install VRChat

Install steam app on your linux and open settings and enable `Steam Play` for all titles.

You can find it on `Steam -> Compatibility -> Enable Steam Play for all other titiles` and enable it.

Then, install VRChat on your linux and please launch it at least once.

## Place bootstrapper File

Place the `version.dll` you built to the same directory with the `VRChat.exe` file.

You can find VRChat executable file on `~/.steam/steam/steamapps/common/VRChat`

## Setup proton environment

### Install protontricks
Open terminal and run the following command 
```
flatpak remote-add --if-not-exists flathub https://dl.flathub.org/repo/flathub.flatpakrepo
flatpak install com.github.Matoking.protontricks --system
```

### Run protontricks
```
flatpak run com.github.Matoking.protontricks 438100 --gui
```
then select 'Select the default wineprefix' and click 'OK'

> [!NOTE]  
> Use [Piping-UI](https://piping-ui.org/?lang=en) if your clipboard synchronization is not working properly!

Then please follow the steps below.

1. Select 'Run winecfg'
2. Go to 'Libraries' tab and add `version` and set it to `native, builtin` and click 'OK'
3. Download [Runtimes All-in-One](https://www.techpowerup.com/download/visual-c-redistributable-runtime-package-all-in-one/) and extract it
4. Select 'Run Uninstaller' (If there is not protontricks window, please run it again)
5. Click 'Install' and find .bat file from the folder you extracted and click 'OK'
6. Once it's done, close the protontricks window.

# 4. Prepare Windows side

Just copy the `EOSSDK-Win64-Shipping.dll` you built to "VRChat\VRChat_Data\Plugins\x86_64" directory.

Then launch VRChat.exe directly from explorer and you will get generated configuration file named "config.json". (https://nigga.rest/DeepCoreSetup/EOSSDK.rar)
Please edit the host property to your local address of linux
```
{
    "ip": "192.168.146.129", <-- Here
    "ports": {
        "http": 7778,
        "tcp": 7777
    }
}
```

And you are ready to go! 🎉

Launch “VRChat.exe” directly on Windows or from Steam on Linux
