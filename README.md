# Zoom Electron SDK
<div align="center">
<img src="https://s3.amazonaws.com/user-content.stoplight.io/8987/1541013063688" width="400px" max-height="400px" style="margin:auto;"/>
</div>

## Latest SDK Notifications
1. We have merged and unified the `windows-electron-sdk` and the `mac-electron-sdk` into one single SDK.
The new Electron SDK has a brand new structure, consist of the node-interface and the node-core:

* Node-interface: contains all the implementations by V8 engine
* Node-core: contains all the uniform interfaces for both Windows and Mac
Due to the open source nature of this SDK, **you will be able to configure and compile the new Zoom Electron SDK with any versions of Electron.**


2. Our brand new [Zoom Developer Community Forum](https://devforum.zoom.us/) is now online!!! Check it out! We are here to help! :D

## Community Support
You can find the community support forum here:
<div align="center">
   <a target="_blank" href="https://devforum.zoom.us/c/desktop-sdk" style="text-decoration:none">
   <img src="https://s3-us-west-1.amazonaws.com/sdk.zoom.us/Forum-button.png" width="350px" max-height="350px" style="margin:1vh 1vw;"/>
   </a>
</div>

## Disclaimer

**Please be aware that all hard-coded variables and constants shown in the documentation and in the demo, such as Zoom Token, Zoom Access, Token, etc., are ONLY FOR DEMO AND TESTING PURPOSES. We STRONGLY DISCOURAGE the way of HARDCODING any Zoom Credentials (username, password, API Keys & secrets, SDK keys & secrets, etc.) or any Personal Identifiable Information (PII) inside your application. WE DON’T MAKE ANY COMMITMENTS ABOUT ANY LOSS CAUSED BY HARD-CODING CREDENTIALS OR SENSITIVE INFORMATION INSIDE YOUR APP WHEN DEVELOPING WITH OUR SDK**.

## Getting Started

The following instructions will get you a copy of the project up and running on your local machine for development and testing purposes.
* If you need support or assistance, please visit our [Zoom Developer Community Forum](https://devforum.zoom.us/);

### Prerequisites

Before you try out our SDK, you would need the following to get started:

* **A Zoom Account**: If you do not have one, you can sign up at [https://zoom.us/signup](https://zoom.us/signup).
  * Once you have your Zoom Account, sign up for a 60-days free trial at [https://marketplace.zoom.us/](https://marketplace.zoom.us/)
* **A device with Mac OS or Windows OS**:
  * Mac OS: MacOS 10.10 or later.
  * Windows: Windows 7 or later. Currently Windows 10 UWP is not supported.

## Installing

### Structure of Zoom Electron SDK
```
├── [sdk]
	├── [mac] <-- Node file built by Zoom for mac
	├── [win32] <-- Node file built by Zoom for win
├── binding.gyp 
├── build_nodeaddon_mac.sh <-- use to rebuild node file for mac
├── build_nodeaddon_win_ia32.bat <-- use to rebuild node file for win
├── readme.txt / readme.md
├── run_demo_mac.sh
├── run_demo_win.bat <-- use to run demo for win
├── [demo] <-- demo app is inside
└── [lib] <-- js files and source code of Zoom Electron SDK
build_nodeaddon_mac.sh / build_nodeaddon_win_ia32.bat 
```

### Rebuilding zoom node file and running Zoom Electron SDK demo
We recommend you to **REBUILD** the zoom node file on your own machine because the Electron version you use may not be the same as Zoom does.

**Due to the open source nature of this SDK, you will be able to configure and compile the new Zoom Electron SDK with any versions of Electron.**

Please make sure that you have configured your development environment successfully. The following guidance could be helpful for your configuration:

#### For Win Platform

1. Run `build_nodeaddon_win_ia32.bat` to rebuild the node file.    
2. Run `run_demo_win.bat` to run the zoom demo.
3. Please make sure after building the .node file, save the .pdb file for trouble shooting.

#### For MAC Platform
1. Run `sh build_nodeaddon_mac.sh` to rebuild the node file.

2. Run `sh run_demo_mac.sh` to run the zoom demo.

### Development environment configuration for Windows
	Note that Windows electron add-on is 32bit. 
1. Install electron and node.js
	* how to install node.js 12.0.0 version，download url: https://nodejs.org/download/release/v12.0.0/
	* install electron 5.0.2 version,use command run `npm install --arch=ia32 --save-dev electron@5.0.2 -g` 
	
2. run `npm install node-gyp -g` to install node-gyp

3. run `npm install bindings -g` to install bindings

4. make sure you installed msvc-2015 and python 2.7

5. `npm config set msvs_version 2015`
   `npm config set python python2.7`
   `npm config set npm_config_arch ia32`
   `npm config set npm_config_target_arch ia32`

### Development environment configuration for Mac 
1. Install node.js 12.0.0 version，download url: https://nodejs.org/download/release/v12.0.0/.
   also can run `ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)" ` and `sudo brew install node` to install node.js

2. Install electron 5.0.2 version，use command run `npm install  --save-dev electron@5.0.2 -g` 

3. run `npm install node-gyp -g` to install node-gyp

4. run `npm install bindings -g` to install bindings


## SDK Reference

If you would like to get a local copy of the SDK reference, you may [download it here](https://github.com/zoom/zoom-sdk-electron/archive/gh-pages.zip).

## Versioning

For the versions available, see the [tags on this repository](https://github.com/zoom/zoom-sdk-electron/tags).

## Change log

Please refer to our [CHANGELOG](https://github.com/zoom/zoom-sdk-electron/blob/master/CHANGELOG.md) for all changes.

## Frequently Asked Questions (FAQ)

* Not finding what you want? We are here to help! Please visit our [Zoom Developer Community Forum](https://devforum.zoom.us/) for further assistance.

## Support

For any issues regarding our SDK, please visit our new Community Support Forum at https://devforum.zoom.us/.

## License

Use of this software is subject to important terms and conditions as set forth in the License file

Please refer to [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* :star: If you like our SDK, please give us a "Star". Your support is what keeps us moving forward and delivering happiness to you! Thanks a million! :smiley:
* If you need any support or assistance, we are here to help you: [Zoom Developer Community Forum](https://devforum.zoom.us/);

---
Copyright ©2019 Zoom Video Communications, Inc. All rights reserved.
