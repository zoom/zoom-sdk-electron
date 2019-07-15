# CHANGELOG

## 2019-07-15 @ [4.4.55130.0712](https://github.com/zoom/zoom-sdk-electron/releases/tag/v4.4.55130.0712)

We have merged and unified the `windows-electron-sdk` and the `mac-electron-sdk` into one single SDK.

The new Electron SDK has a brand new structure, consist of the `node-interface` and the `node-core`:

* **Node-interface**: contains all the implementations by V8 engine
* **Node-core**: contains all the uniform interfaces for both Windows and Mac

Due to the open source nature of this SDK, you will be able to configure and compile the new Zoom Electron SDK with any versions of Electron.

**Added**

* Added newly developed interfaces by referring to the previous Windows Electron SDK
* Added newly developed interfaces by referring to the previous Mac Electron SDK
* Can support any version of Electron
