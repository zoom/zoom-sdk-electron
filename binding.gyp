{
'variables':{
'module_name': "zoomsdk",
'module_mac': "./../sdk/mac",
"module_win32":"./../sdk/win32",
"module_win64":"./../sdk/win64",
'module_32pdbfile_name':"./../sdk/win32/zoomsdk.pdb",
'module_64pdbfile_name':"./../sdk/win64/zoomsdk.pdb",
},
      "targets":[
      {
      'target_name':"<(module_name)",
      
      'conditions':[
      [
		  'OS=="mac"',
		  {
		      'product_dir':"<(module_mac)",
			  'sources':[
			     "./lib/node_add_on/mac/zoom_native_sdk_wrap_core.mm",
			     "./lib/node_add_on/mac/auth_service_wrap_core.mm",
			     "./lib/node_add_on/zoom_node_addon.cpp",
			     "./lib/node_add_on/mac/sdk_native_error.mm",
			     "./lib/node_add_on/mac/authServiceDelegate.mm",
			     "./lib/node_add_on/mac/meeting_service_wrap_core.mm",
			     "./lib/node_add_on/mac/meetingServiceDelegate.mm",
                 "./lib/node_add_on/mac/meeting_ui_service.mm",
                 "./lib/node_add_on/mac/meeting_as_service.mm",
                 "./lib/node_add_on/mac/meeting_audio_service.mm",
                 "./lib/node_add_on/mac/meeting_video_service.mm",
                 "./lib/node_add_on/mac/meeting_participants_service.mm",
                 "./lib/node_add_on/mac/zoom_setting_service.mm",
                 "./lib/node_add_on/mac/setting_video_service.mm",
                 "./lib/node_add_on/mac/setting_audio_service.mm",
                 "./lib/node_add_on/mac/setting_general_service.mm",
                 "./lib/node_add_on/mac/setting_recording_service.mm",
                 "./lib/node_add_on/mac/customized_resource_wrap_core.mm",
                 "./lib/node_add_on/mac/meeting_share_service.mm",
                 "./lib/node_add_on/mac/meeting_H323_service.mm",
                 "./lib/node_add_on/mac/meeting_config_service.mm"
			  ],
			  'mac_framework_dirs':[
			  './../sdk/mac/ZoomSDK',
			  ],
			  'link_settings':{
			  'libraries':[
			   "ZoomSDK.framework",

			   ],
			   },
		  },
		  ],
		  [
		  'OS=="win" and target_arch=="x64"',
		  {
		   'product_dir':"<(module_win64)",
		   'configurations': {
				'Release': {
				  'msvs_settings': {
					'VCLinkerTool': {
					  'GenerateDebugInformation': 'true',
					  'GenerateMapFile': 'true',
					  'ProgramDatabaseFile': "<(module_64pdbfile_name)",
					},
				  }, 
				},
		  }, # configurations
		  }
		  ],
		  [
		  'OS=="win" and target_arch=="ia32"',
		  {
		   'product_dir':"<(module_win32)",
		     'configurations': {
				'Release': {
				  'msvs_settings': {
					'VCLinkerTool': {
					  'GenerateDebugInformation': 'true',
					  'GenerateMapFile': 'true',
					  'ProgramDatabaseFile': "<(module_32pdbfile_name)",
					},
				  }, 
				},
		  }, # configurations
		  }
		  ],
		  [
		  'OS=="win"',
		  {
		  "sources":[
			  "./lib/node_add_on/win/zoom_native_sdk_wrap_core.cpp",
			  "./lib/node_add_on/win/auth_service_wrap_core.cpp", 
			  "./lib/node_add_on/win/meeting_service_wrap_core.cpp",
			  "./lib/node_add_on/win/setting_service_wrap_core.cpp",
			  
			  "./lib/node_add_on/win/meeting_annotation_wrap_core.cpp",
			  "./lib/node_add_on/win/meeting_audio_wrap_core.cpp",
			  "./lib/node_add_on/win/meeting_video_wrap_core.cpp",
			  "./lib/node_add_on/win/meeting_share_wrap_core.cpp",
			  "./lib/node_add_on/win/meeting_config_wrap_core.cpp",
			  "./lib/node_add_on/win/meeting_participants_wrap_core.cpp",
			  "./lib/node_add_on/win/meeting_h323_wrap_core.cpp",
			  "./lib/node_add_on/win/setting_video_wrap_core.cpp",
			  "./lib/node_add_on/win/setting_audio_wrap_core.cpp",
			  "./lib/node_add_on/win/setting_general_wrap_core.cpp",
			  "./lib/node_add_on/win/setting_recording_wrap_core.cpp",
			  
			  "./lib/node_add_on/win/customized_resource_wrap_core.cpp",
			  "./lib/node_add_on/zoom_node_addon.cpp",
			  "./lib/node_add_on/node_res.rc",
			  "./lib/node_add_on/win/zoom_native_to_wrap.cpp"

		  ],
			  
			  'defines':['BUILD_WIN'],
		  
		  }
		  
		  ]

		 ]
      },
	 
	  

      ]
}
