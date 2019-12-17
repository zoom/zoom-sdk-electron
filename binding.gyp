{
'variables':{
'module_name': "zoomsdk",
'module_mac': "./../sdk/mac",
"module_win32":"./../sdk/win32",
"module_win64":"./../sdk/win64",
'module_32pdbfile_name':"./../sdk/win32/zoomsdk.pdb",
'module_64pdbfile_name':"./../sdk/win64/zoomsdk.pdb",

'render_module_name': "zoomsdk_render",
'render_module_32pdbfile_name':"./../sdk/win32/zoomsdk_render.pdb",
'render_module_64pdbfile_name':"./../sdk/win64/zoomsdk_render.pdb",

},
      "targets":[
      {
      'target_name':"<(module_name)",
      
      'conditions':[
      [
		  'OS=="mac"',
		  {
		      # 'product_dir':"<(module_mac)",
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
                 "./lib/node_add_on/mac/meeting_config_service.mm",
                 "./lib/node_add_on/mac/meeting_premeeting_service.mm",
                 "./lib/node_add_on/mac/task_to_main.mm",
                 "./lib/node_add_on/zoom_node_meeting_annotation.cpp",
				  "./lib/node_add_on/zoom_node_meeting_audio_ctrl.cpp",
				  "./lib/node_add_on/zoom_node_meeting_video_ctrl.cpp",
				  "./lib/node_add_on/zoom_node_meeting_participants_ctrl.cpp",
				  "./lib/node_add_on/zoom_node_meeting_share_ctrl.cpp",
				  "./lib/node_add_on/zoom_node_meeting_h323_ctrl.cpp",
				  "./lib/node_add_on/zoom_node_meeting_config_ctrl.cpp",
				  "./lib/node_add_on/zoom_node_setting_video_ctrl.cpp",
				  "./lib/node_add_on/zoom_node_setting_audio_ctrl.cpp",
				  "./lib/node_add_on/zoom_node_setting_general_ctrl.cpp",
				  "./lib/node_add_on/zoom_node_setting_recording_ctrl.cpp",
				  "./lib/node_add_on/zoom_node_customized_resource.cpp",
				  "./lib/node_add_on/zoom_node_direct_share_helper.cpp",
				  "./lib/node_add_on/zoom_node_video_raw_data.cpp",
				  "./lib/node_add_on/zoom_node_audio_raw_data.cpp",
				  "./lib/node_add_on/zoom_node_share_raw_data.cpp",
				  "./lib/node_add_on/zoom_v8_to_c.cpp",
				  "./lib/node_add_on/run_task_to_main_thread.cpp",
				  "./lib/node_add_on/zoom_node_raw_data_license.cpp",
				  "./lib/node_add_on/zoom_raw_data_wrap.cpp",
				  "./lib/node_add_on/zoom_node_setting_ui_strategy_ctrl.cpp",
                  "./lib/node_add_on/zoom_node_sdk_sms_helper.cpp",
                  "./lib/node_add_on/mac/zoom_sms_wrap.mm",

			      "./lib/node_add_on/zoom_node_setting_statistic_ctrl.cpp",
			      "./lib/node_add_on/zoom_node_setting_accessibility_ctrl.cpp",
			      "./lib/node_add_on/mac/settingServiceDelegate.mm",
			      "./lib/node_add_on/mac/setting_statistic_service.mm",
			      "./lib/node_add_on/mac/setting_accessibility_service.mm",
			       "./lib/node_add_on/raw_data_format.cpp",
			      "./lib/node_add_on/uv_ipc_common.cpp",
			      "./lib/node_add_on/raw_data_uv_ipc_server.cpp",

			  ],
			  'mac_framework_dirs':[
			  './../sdk/mac/ZoomSDK',
			  ],
			  'link_settings':{
			  'libraries':[
			   "ZoomSDK.framework",

			   ],
			   },
   		      "xcode_settings":{
                    "DEBUG_INFORMATION_FORMAT": "dwarf-with-dsym",
                    "BUILD_DIR":"<(module_mac)",
                    "OTHER_CPLUSPLUSFLAGS" : [ '-ObjC++', "-std=c++11", "-stdlib=libc++",  '-fvisibility=hidden','-frtti'],
                    "OTHER_LDFLAGS": [ "-stdlib=libc++"],
                    "DEPLOYMENT_POSTPROCESSING": "YES",
           

	        }
			   
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
			  "./lib/node_add_on/win/premeeting_service_wrap_core.cpp",
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
			  "./lib/node_add_on/win/setting_ui_strategy_wrap_core.cpp",
			  
			  "./lib/node_add_on/win/setting_statistic_wrap_core.cpp",
			  "./lib/node_add_on/win/setting_accessibility_wrap_core.cpp",
			  
			  "./lib/node_add_on/win/setting_recording_wrap_core.cpp",
			  "./lib/node_add_on/win/directshare_helper_wrap_core.cpp",
			  "./lib/node_add_on/win/customized_resource_wrap_core.cpp",
			  "./lib/node_add_on/win/zoom_sdk_sms_helper_wrap_core.cpp",
			  "./lib/node_add_on/zoom_node_addon.cpp",
			  "./lib/node_add_on/node_res.rc",
			  "./lib/node_add_on/win/zoom_native_to_wrap.cpp",
			  
			  "./lib/node_add_on/zoom_node_meeting_annotation.cpp",
			  "./lib/node_add_on/zoom_node_meeting_audio_ctrl.cpp",
			  "./lib/node_add_on/zoom_node_meeting_video_ctrl.cpp",
			  "./lib/node_add_on/zoom_node_meeting_participants_ctrl.cpp",
			  "./lib/node_add_on/zoom_node_meeting_share_ctrl.cpp",
			  "./lib/node_add_on/zoom_node_meeting_h323_ctrl.cpp",
			  "./lib/node_add_on/zoom_node_meeting_config_ctrl.cpp",
			  "./lib/node_add_on/zoom_node_setting_video_ctrl.cpp",
			  "./lib/node_add_on/zoom_node_setting_audio_ctrl.cpp",
			  "./lib/node_add_on/zoom_node_setting_general_ctrl.cpp",
			  "./lib/node_add_on/zoom_node_setting_ui_strategy_ctrl.cpp",
			  
			  "./lib/node_add_on/zoom_node_setting_statistic_ctrl.cpp",
			  "./lib/node_add_on/zoom_node_setting_accessibility_ctrl.cpp",
			  
			  "./lib/node_add_on/zoom_node_setting_recording_ctrl.cpp",
			  "./lib/node_add_on/zoom_node_customized_resource.cpp",
			  "./lib/node_add_on/zoom_node_direct_share_helper.cpp",
			  "./lib/node_add_on/zoom_node_video_raw_data.cpp",
			  "./lib/node_add_on/zoom_node_audio_raw_data.cpp",
			  "./lib/node_add_on/zoom_node_share_raw_data.cpp",
			  "./lib/node_add_on/zoom_v8_to_c.cpp",
			  "./lib/node_add_on/raw_data_format.cpp",
			  "./lib/node_add_on/uv_ipc_common.cpp",
			  "./lib/node_add_on/raw_data_uv_ipc_server.cpp",
			  "./lib/node_add_on/run_task_to_main_thread.cpp",
			  "./lib/node_add_on/zoom_raw_data_wrap.cpp",
			  "./lib/node_add_on/zoom_node_raw_data_license.cpp",
			  "./lib/node_add_on/zoom_node_sdk_sms_helper.cpp"
			  
			  

		  ],
			  
			  'defines':['BUILD_WIN'],
		  
		  }
		  
		  ]

		 ]
      },
	 
	 {
	 'target_name':"<(render_module_name)",
	 
	 'conditions':[
	  [
		  'OS=="mac"',
		  {
		      # 'product_dir':"<(module_mac)",
			  'sources':[
			     "./lib/node_add_on/zoom_node_render_addon.cpp",
			     "./lib/node_add_on/zoom_v8_to_c.cpp",
			     "./lib/node_add_on/uv_ipc_common.cpp",
			     "./lib/node_add_on/zoom_v8_to_c.cpp",
			  ],
			  'mac_framework_dirs':[
			  './../sdk/mac/ZoomSDK',
			  ],
			  'link_settings':{
			  'libraries':[
			   "ZoomSDK.framework",

			   ],
			   },
			   "xcode_settings":{
                    "DEBUG_INFORMATION_FORMAT": "dwarf-with-dsym",
                    "BUILD_DIR":"<(module_mac)",
                    "OTHER_CPLUSPLUSFLAGS" : [ '-ObjC++', "-std=c++11", "-stdlib=libc++",  '-fvisibility=hidden','-frtti'],
                    "OTHER_LDFLAGS": [ "-stdlib=libc++"],
                    "DEPLOYMENT_POSTPROCESSING": "YES",
	        }
			   
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
					  'ProgramDatabaseFile': "<(render_module_64pdbfile_name)",
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
					  'ProgramDatabaseFile': "<(render_module_32pdbfile_name)",
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
			
			  "./lib/node_add_on/zoom_node_render_addon.cpp",
			  "./lib/node_add_on/node_res.rc",
			  "./lib/node_add_on/win/zoom_native_to_wrap.cpp",
			  
			  "./lib/node_add_on/zoom_v8_to_c.cpp",
			 
			  "./lib/node_add_on/uv_ipc_common.cpp",
			  
		  ],
			  
			'defines':['BUILD_WIN'],  
		  
		  }
		  
		  ]
	 ]
	 },
	 
	  

      ]
}
