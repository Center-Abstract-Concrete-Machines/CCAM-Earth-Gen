{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 8,
			"minor" : 5,
			"revision" : 7,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 352.0, 1524.0, 932.0, 562.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "CCAM-EARTH",
		"assistshowspatchername" : 0,
		"boxes" : [ 			{
				"box" : 				{
					"fontface" : 0,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-18",
					"maxclass" : "number~",
					"mode" : 2,
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "signal", "float" ],
					"patching_rect" : [ 717.0, 471.0, 56.0, 22.0 ],
					"sig" : 0.0
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"maxclass" : "live.scope~",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 632.666677355766296, 554.0, 184.0, 68.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgmode" : 0,
					"border" : 0,
					"clickthrough" : 0,
					"enablehscroll" : 0,
					"enablevscroll" : 0,
					"id" : "obj-17",
					"lockeddragscroll" : 0,
					"lockedsize" : 0,
					"maxclass" : "bpatcher",
					"name" : "oopsy.maxpat",
					"numinlets" : 1,
					"numoutlets" : 0,
					"offset" : [ 0.0, 0.0 ],
					"patching_rect" : [ 496.0, 378.702135741710663, 128.0, 128.0 ],
					"viewvisibility" : 1
				}

			}
, 			{
				"box" : 				{
					"basictuning" : 440,
					"data" : 					{
						"clips" : [ 							{
								"absolutepath" : "Tbn-ord-A#1-ff.wav",
								"filename" : "Tbn-ord-A#1-ff.wav",
								"filekind" : "audiofile",
								"id" : "u610001493",
								"selection" : [ 0.0, 1.0 ],
								"loop" : 1,
								"content_state" : 								{
									"loop" : 1
								}

							}
 ]
					}
,
					"followglobaltempo" : 0,
					"formantcorrection" : 0,
					"id" : "obj-39",
					"maxclass" : "playlist~",
					"mode" : "basic",
					"numinlets" : 1,
					"numoutlets" : 5,
					"originallength" : [ 0.0, "ticks" ],
					"originaltempo" : 120.0,
					"outlettype" : [ "signal", "signal", "signal", "", "dictionary" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 313.333342671394348, 361.0, 150.0, 30.0 ],
					"pitchcorrection" : 0,
					"quality" : "basic",
					"timestretch" : [ 0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-16",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 375.666677355766296, 566.0, 150.0, 34.0 ],
					"text" : "cvout1\n"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-15",
					"maxclass" : "live.scope~",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 358.666677355766296, 581.0, 184.0, 68.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-14",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 375.666677355766296, 651.0, 150.0, 34.0 ],
					"text" : "cvout2\n"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-12",
					"maxclass" : "live.scope~",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 358.666677355766296, 668.0, 184.0, 68.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.4, 0.4, 0.749019607843137, 0.0 ],
					"fontface" : 0,
					"fontname" : "DIN Condensed Bold",
					"fontsize" : 20.0,
					"id" : "obj-65",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 323.333342969417572, 49.333334803581238, 228.0, 31.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 58.611111111111086, 28.5, 228.0, 31.0 ],
					"text" : "Silo",
					"textcolor" : [ 0.062745098039216, 0.062745098039216, 0.117647058823529, 1.0 ],
					"textjustification" : 1
				}

			}
, 			{
				"box" : 				{
					"angle" : 270.0,
					"bgcolor" : [ 0.894117647058824, 0.83921568627451, 1.0, 1.0 ],
					"id" : "obj-66",
					"maxclass" : "panel",
					"mode" : 0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 341.333343505859375, 39.333334505558014, 182.0, 36.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 52.184027777777715, 28.0, 229.0, 32.0 ],
					"proportion" : 0.5
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-59",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 358.666677355766296, 95.333336174488068, 60.0, 48.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 208.611111111111086, 261.0, 60.0, 48.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "BPM[3]",
							"parameter_mmax" : 1.0,
							"parameter_shortname" : "wet/dry",
							"parameter_steps" : 127,
							"parameter_type" : 0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "live.dial[3]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-60",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 433.333346247673035, 170.000005066394806, 60.0, 48.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 133.611111111111086, 261.0, 60.0, 48.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "BPM[4]",
							"parameter_mmax" : 120.0,
							"parameter_mmin" : 37.0,
							"parameter_shortname" : "MIDI Offset",
							"parameter_steps" : 127,
							"parameter_type" : 1,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "live.dial[4]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-61",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 358.666677355766296, 170.000005066394806, 60.0, 48.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 58.611111111111086, 261.0, 60.0, 48.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "BPM[5]",
							"parameter_mmax" : 8.0,
							"parameter_mmin" : 1.0,
							"parameter_shortname" : "quantize",
							"parameter_steps" : 8,
							"parameter_type" : 1,
							"parameter_unitstyle" : 0
						}

					}
,
					"varname" : "live.dial[5]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-58",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 508.666681826114655, 95.333336174488068, 60.0, 48.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 208.611111111111086, 201.0, 60.0, 48.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "BPM[2]",
							"parameter_mmax" : 16.0,
							"parameter_mmin" : 0.00001,
							"parameter_shortname" : "LFO_hz",
							"parameter_steps" : 127,
							"parameter_type" : 0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "live.dial[2]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-57",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 435.333346307277679, 95.333336174488068, 60.0, 48.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 133.611111111111086, 201.0, 60.0, 48.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "BPM[1]",
							"parameter_mmax" : 1.0,
							"parameter_shortname" : "lfo offsets",
							"parameter_steps" : 127,
							"parameter_type" : 0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "live.dial[1]"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-56",
					"maxclass" : "live.dial",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "float" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 513.666677355766296, 170.000005066394806, 60.0, 48.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 58.611111111111086, 201.0, 60.0, 48.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "BPM",
							"parameter_mmax" : 100.0,
							"parameter_mmin" : 1.0,
							"parameter_shortname" : "bandwidth",
							"parameter_steps" : 200,
							"parameter_type" : 0,
							"parameter_unitstyle" : 1
						}

					}
,
					"varname" : "live.dial"
				}

			}
, 			{
				"box" : 				{
					"angle" : 270.0,
					"bgcolor" : [ 0.76078431372549, 0.76078431372549, 0.898039215686275, 1.0 ],
					"border" : 3,
					"bordercolor" : [ 0.584313725490196, 0.584313725490196, 0.647058823529412, 1.0 ],
					"id" : "obj-62",
					"maxclass" : "panel",
					"mode" : 0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 339.33334344625473, 85.333335876464844, 252.0, 145.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 39.611111111111086, 187.0, 252.0, 134.0 ],
					"proportion" : 0.5
				}

			}
, 			{
				"box" : 				{
					"angle" : 270.0,
					"border" : 3,
					"grad1" : [ 0.0, 0.0, 0.0, 1.0 ],
					"grad2" : [ 0.243137254901961, 0.905882352941176, 0.537254901960784, 1.0 ],
					"id" : "obj-63",
					"maxclass" : "panel",
					"mode" : 1,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 323.333342969417572, 23.333334028720856, 279.0, 223.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 15.0, 15.0, 300.0, 465.0 ],
					"proportion" : 0.5
				}

			}
, 			{
				"box" : 				{
					"angle" : 270.0,
					"bgcolor" : [ 0.180392156862745, 0.180392156862745, 0.333333333333333, 1.0 ],
					"id" : "obj-5",
					"maxclass" : "panel",
					"mode" : 0,
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 313.333342671394348, 12.000000357627869, 300.0, 242.5 ],
					"presentation" : 1,
					"presentation_rect" : [ 6.0, 0.0, 330.0, 495.0 ],
					"proportion" : 0.5,
					"rounded" : 20
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-4",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 211.0, 645.0, 45.0, 45.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-3",
					"lastchannelcount" : 0,
					"maxclass" : "live.gain~",
					"numinlets" : 2,
					"numoutlets" : 5,
					"outlettype" : [ "signal", "signal", "", "float", "list" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 211.0, 486.0, 48.0, 136.0 ],
					"saved_attribute_attributes" : 					{
						"valueof" : 						{
							"parameter_longname" : "live.gain~",
							"parameter_mmax" : 6.0,
							"parameter_mmin" : -70.0,
							"parameter_shortname" : "live.gain~",
							"parameter_type" : 0,
							"parameter_unitstyle" : 4
						}

					}
,
					"varname" : "live.gain~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-1",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 12,
					"outlettype" : [ "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal", "signal" ],
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 8,
							"minor" : 5,
							"revision" : 7,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "dsp.gen",
						"rect" : [ 33.0, 84.0, 2494.0, 1283.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 1,
						"objectsnaponopen" : 1,
						"statusbarvisible" : 2,
						"toolbarvisible" : 1,
						"lefttoolbarpinned" : 0,
						"toptoolbarpinned" : 0,
						"righttoolbarpinned" : 0,
						"bottomtoolbarpinned" : 0,
						"toolbars_unpinned_last_save" : 0,
						"tallnewobj" : 0,
						"boxanimatetime" : 200,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"description" : "",
						"digest" : "",
						"tags" : "",
						"style" : "",
						"subpatcher_template" : "",
						"assistshowspatchername" : 0,
						"boxes" : [ 							{
								"box" : 								{
									"id" : "obj-89",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1036.0, 855.0, 77.0, 22.0 ],
									"text" : "go_unit_sine"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-86",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 62.000001728534698, 322.333358764648438, 40.0, 22.0 ],
									"text" : "mix"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-87",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 130.5, 322.333358764648438, 79.0, 22.0 ],
									"text" : "mix"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 1.0, 0.419607843137255, 0.141176470588235, 1.0 ],
									"id" : "obj-88",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 190.5, 269.000024437904358, 248.0, 22.0 ],
									"text" : "param knob1_gateInput 0. @min 0. @max 1."
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-85",
									"linecount" : 5,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1633.0, 434.0, 150.0, 89.0 ],
									"text" : "8 -- 1 \n7 -- 1\n6 -- 1 \n5 -- 1 \n4 -- 2\n"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-83",
									"maxclass" : "newobj",
									"numinlets" : 4,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1577.0, 891.0, 74.0, 22.0 ],
									"text" : "go_quantize"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-81",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1830.766694486141205, 549.400006175041199, 32.0, 22.0 ],
									"text" : "floor"
								}

							}
, 							{
								"box" : 								{
									"code" : "// use a Data to store the previous 'y' values for each resonator\r\nData hy1(8);\r\nData hy2(8);\r\n\r\ngain = 1/sqrt(8);\r\n\r\n\t\t\t\r\n// using abs() to ensure it doesn't blow up with \r\n// negative bandwidth:\nbw_rps = abs(knob6_bandwidth) * twopi/samplerate;\r\n\r\nx = in1;\r\nsum = 0;\r\nfor (i=0; i<numVoices; i+= 1) {\r\n\t// read this resonator's data:\r\n\ty2 = peek(hy2, i);\r\n\ty1 = peek(hy1, i);\r\n\t\r\n\t// this could be better optimized \r\n\t// to calculate coefficients less frequently\r\n\t// if it is known that they cannot change at any time\r\n\tfreq = peek(fqs, i);\r\n\tamp = peek(amps, i);\r\n\t// convert to radians per sample:\r\n\tfreq_rps = freq * twopi/samplerate;\r\n\t// calculate coefficients:\n\tb = 2 * cos(freq_rps) * exp(bw_rps * -0.5);\n\tc = -exp(-bw_rps);\n\ta = 1 - ((c + b));\r\n\t\r\n\t// compute next y:\r\n\ty = a*x + b*y1 + c*y2;\r\n\t// update this resonator's history:\r\n\tpoke(hy2, y1, i);\r\n\tpoke(hy1, y, i);\r\n\r\n\t// mix into output:\r\n\tsum += y * amp;\r\n}\r\n\r\nout1 = sum * gain;",
									"fontface" : 0,
									"fontname" : "<Monospaced>",
									"fontsize" : 12.0,
									"id" : "obj-79",
									"maxclass" : "codebox",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 62.000001728534698, 376.333343207836151, 565.0, 617.0 ]
								}

							}
, 							{
								"box" : 								{
									"color" : [ 1.0, 0.419607843137255, 0.141176470588235, 1.0 ],
									"id" : "obj-76",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1830.766694486141205, 519.800012350082397, 224.0, 22.0 ],
									"text" : "param knob4_quantize @min 1 @max 8"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-65",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1284.100016117095947, 519.800012350082397, 108.0, 22.0 ],
									"text" : "oopsy.ctrl.smooth3"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-50",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1137.866622924804688, 283.0, 19.0, 22.0 ],
									"text" : "7"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-52",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 1136.533321917057037, 329.0, 67.0, 22.0 ],
									"text" : "peek amps"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-53",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1039.966624617576599, 283.0, 19.0, 22.0 ],
									"text" : "6"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-55",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 1038.633323609828949, 329.0, 67.0, 22.0 ],
									"text" : "peek amps"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-56",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 922.666637420654297, 283.0, 19.0, 22.0 ],
									"text" : "5"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-58",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 921.333336412906647, 329.0, 67.0, 22.0 ],
									"text" : "peek amps"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-59",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 819.33330100774765, 283.0, 19.0, 22.0 ],
									"text" : "4"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-63",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 819.33330100774765, 329.0, 67.0, 22.0 ],
									"text" : "peek amps"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-47",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1160.533321917057037, 150.0, 19.0, 22.0 ],
									"text" : "3"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-48",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 1159.200020909309387, 196.0, 67.0, 22.0 ],
									"text" : "peek amps"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-45",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1062.633323609828949, 150.0, 19.0, 22.0 ],
									"text" : "2"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-46",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 1061.300022602081299, 196.0, 67.0, 22.0 ],
									"text" : "peek amps"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-41",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 945.333336412906647, 150.0, 19.0, 22.0 ],
									"text" : "1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-42",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 944.000035405158997, 196.0, 67.0, 22.0 ],
									"text" : "peek amps"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-40",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 842.0, 150.0, 19.0, 22.0 ],
									"text" : "0"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-39",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 840.66669899225235, 196.0, 67.0, 22.0 ],
									"text" : "peek amps"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 1.0, 0.611764705882353, 0.611764705882353, 1.0 ],
									"id" : "obj-77",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1137.43330579996109, 369.599999964237213, 79.0, 22.0 ],
									"text" : "out 10 led8"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 1.0, 0.611764705882353, 0.611764705882353, 1.0 ],
									"id" : "obj-78",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1038.633323609828949, 372.0, 79.0, 22.0 ],
									"text" : "out 9 led7"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 1.0, 0.611764705882353, 0.611764705882353, 1.0 ],
									"id" : "obj-80",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 921.333336412906647, 372.0, 79.0, 22.0 ],
									"text" : "out 8 led6"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 1.0, 0.611764705882353, 0.611764705882353, 1.0 ],
									"id" : "obj-126",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 819.33330100774765, 372.0, 79.0, 22.0 ],
									"text" : "out 7 led5"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 1.0, 0.611764705882353, 0.611764705882353, 1.0 ],
									"id" : "obj-135",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1159.200020909309387, 240.666669905185699, 79.0, 22.0 ],
									"text" : "out 6 led4"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 1.0, 0.611764705882353, 0.611764705882353, 1.0 ],
									"id" : "obj-136",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1056.000038743019104, 240.666669905185699, 79.0, 22.0 ],
									"text" : "out 5 led3"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 1.0, 0.611764705882353, 0.611764705882353, 1.0 ],
									"id" : "obj-185",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 944.000035405158997, 240.666669905185699, 79.0, 22.0 ],
									"text" : "out 4 led2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 1.0, 0.611764705882353, 0.611764705882353, 1.0 ],
									"id" : "obj-194",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 840.66669899225235, 240.666669905185699, 79.0, 22.0 ],
									"text" : "out 3 led1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-36",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 348.0, 196.0, 150.0, 34.0 ],
									"text" : "numVoices hardcoded to 8 for CCAM Earth"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-34",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 348.0, 134.800002157688141, 19.0, 22.0 ],
									"text" : "8"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-22",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 348.0, 170.0, 106.0, 22.0 ],
									"text" : "history numVoices"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-20",
									"maxclass" : "newobj",
									"numinlets" : 7,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 77.5, 186.333343207836151, 93.0, 22.0 ],
									"text" : "earth_resonator"
								}

							}
, 							{
								"box" : 								{
									"code" : "s = (in1*2)-1;\r\n\r\nfor (i = 0; i<numVoices;i+=1){\r\n\tsin = go_unit_sine(s);\r\n\tpoke(amps, sin, i);\r\n\ts +=  0.125;\r\n\ts = wrap(s,0,1);\r\n    }\r\n\r\nout1 = peek(amps, 0);",
									"fontface" : 0,
									"fontname" : "<Monospaced>",
									"fontsize" : 12.0,
									"id" : "obj-5",
									"maxclass" : "codebox",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 827.0, 583.833343207836151, 352.333302557468414, 180.166683793067932 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-43",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1284.100016117095947, 549.400006175041199, 32.0, 22.0 ],
									"text" : "floor"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-2",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 1034.633323609828949, 490.400006175041199, 75.0, 22.0 ],
									"text" : "data amps 8"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 1284.100016117095947, 784.0, 68.0, 22.0 ],
									"text" : "data fqs 32"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-44",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 827.200019359588623, 471.400006175041199, 99.0, 22.0 ],
									"text" : "phasor"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-60",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 62.000001728534698, 1001.000023543834686, 33.0, 22.0 ],
									"text" : "* 0.4"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-61",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 62.000001728534698, 1031.000024437904358, 141.0, 22.0 ],
									"text" : "go.allpass.diffuser.stereo"
								}

							}
, 							{
								"box" : 								{
									"code" : "newNote = change(in1) || change(in2);\r\n\r\nout1 = newNote !=1;\r\n\r\n\r\nif(elapsed == 0 || newNote !=1) {\r\nfor(index = 0;index<numVoices;index+=1){\r\n\tmidi = floor((go_quantize(index/numVoices,in2,12)*12) + in1);\r\n\tf = mtof(midi);\r\n\tpoke(fqs,f,index);\r\n\t}\r\n}",
									"fontface" : 0,
									"fontname" : "<Monospaced>",
									"fontsize" : 12.0,
									"id" : "obj-54",
									"maxclass" : "codebox",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1284.100016117095947, 591.000010907649994, 565.666678369045258, 173.000016093254089 ]
								}

							}
, 							{
								"box" : 								{
									"color" : [ 1.0, 0.066666666666667, 0.168627450980392, 1.0 ],
									"id" : "obj-33",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1284.100016117095947, 819.067822694778442, 81.0, 22.0 ],
									"text" : "out 12 cvout2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.274509803921569, 0.125490196078431, 1.0, 1.0 ],
									"id" : "obj-31",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 130.5, 262.0, 29.0, 22.0 ],
									"text" : "in 2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.274509803921569, 0.125490196078431, 1.0, 1.0 ],
									"id" : "obj-30",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 64.500001728534698, 262.0, 28.0, 22.0 ],
									"text" : "in 1"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.274509803921569, 0.125490196078431, 1.0, 1.0 ],
									"id" : "obj-29",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 255.33334082365036, 1143.000027775764465, 35.0, 22.0 ],
									"text" : "out 2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.274509803921569, 0.125490196078431, 1.0, 1.0 ],
									"id" : "obj-28",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 60.000001728534698, 1117.000027000904083, 35.0, 22.0 ],
									"text" : "out 1"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 1.0, 0.066666666666667, 0.168627450980392, 1.0 ],
									"id" : "obj-27",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 827.0, 791.833343207836151, 80.0, 22.0 ],
									"text" : "out 11 cvout1"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.0, 0.850980392156863, 0.192156862745098, 1.0 ],
									"id" : "obj-26",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1799.0, 434.40000331401825, 107.0, 22.0 ],
									"text" : "oopsy.suggestions"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-25",
									"linecount" : 4,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 796.000023722648621, 13.333333730697632, 150.0, 62.0 ],
									"text" : "port cvin 2. These can be reset as both gates or both CV ins in the \"earth-params.json\""
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-24",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 577.333350539207458, 27.333334743976593, 150.0, 20.0 ],
									"text" : "port cvin 1"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 1.0, 0.0, 0.898039215686275, 1.0 ],
									"id" : "obj-21",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1141.333354532718658, 430.333335638046265, 204.0, 22.0 ],
									"text" : "param cvin1_LFO @min 0. @max 1."
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-19",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 577.333350539207458, 97.33333683013916, 89.0, 22.0 ],
									"text" : "oopsy.gate.min"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-16",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 5,
									"outlettype" : [ "", "", "", "", "" ],
									"patching_rect" : [ 574.666683793067932, 133.333337903022766, 100.0, 22.0 ],
									"text" : "oopsy.gate2clock"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 1.0, 0.0, 0.898039215686275, 1.0 ],
									"id" : "obj-17",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 577.333350539207458, 57.333335638046265, 76.0, 22.0 ],
									"text" : "param gate1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-10",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1126.200020909309387, 1147.00000262260437, 86.0, 22.0 ],
									"text" : "oopsy.gate.trig"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-12",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1022.200019359588623, 1147.00000262260437, 86.0, 22.0 ],
									"text" : "oopsy.gate.trig"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-13",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 907.800017654895782, 1146.200002610683441, 86.0, 22.0 ],
									"text" : "oopsy.gate.trig"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-14",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 804.600016117095947, 1146.200002610683441, 86.0, 22.0 ],
									"text" : "oopsy.gate.trig"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-8",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1126.200020909309387, 1038.200001001358032, 86.0, 22.0 ],
									"text" : "oopsy.gate.trig"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-11",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1023.000038743019104, 1038.333335340023041, 86.0, 22.0 ],
									"text" : "oopsy.gate.trig"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-9",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 911.000035405158997, 1038.333335340023041, 86.0, 22.0 ],
									"text" : "oopsy.gate.trig"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-4",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 807.66669899225235, 1038.333335340023041, 86.0, 22.0 ],
									"text" : "oopsy.gate.trig"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.72156862745098, 0.886274509803922, 1.0, 1.0 ],
									"id" : "obj-144",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1126.200020909309387, 1114.200002133846283, 68.0, 22.0 ],
									"text" : "param sw8"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.72156862745098, 0.886274509803922, 1.0, 1.0 ],
									"id" : "obj-145",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1022.200019359588623, 1114.200002133846283, 79.0, 22.0 ],
									"text" : "param sw7"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.72156862745098, 0.886274509803922, 1.0, 1.0 ],
									"id" : "obj-146",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 907.800017654895782, 1116.60000216960907, 70.0, 22.0 ],
									"text" : "param sw6"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.72156862745098, 0.886274509803922, 1.0, 1.0 ],
									"id" : "obj-147",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 804.600016117095947, 1115.800002157688141, 71.0, 22.0 ],
									"text" : "param sw5"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.72156862745098, 0.886274509803922, 1.0, 1.0 ],
									"id" : "obj-124",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1126.200020909309387, 989.400000274181366, 68.0, 22.0 ],
									"text" : "param sw4"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.72156862745098, 0.886274509803922, 1.0, 1.0 ],
									"id" : "obj-125",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1023.000038743019104, 989.000000536441803, 79.0, 22.0 ],
									"text" : "param sw3"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.72156862745098, 0.886274509803922, 1.0, 1.0 ],
									"id" : "obj-123",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 911.000035405158997, 989.000000536441803, 70.0, 22.0 ],
									"text" : "param sw2"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 0.72156862745098, 0.886274509803922, 1.0, 1.0 ],
									"id" : "obj-122",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 807.66669899225235, 989.000000536441803, 71.0, 22.0 ],
									"text" : "param sw1"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 1.0, 0.419607843137255, 0.141176470588235, 1.0 ],
									"id" : "obj-23",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1284.100016117095947, 490.400006175041199, 253.0, 22.0 ],
									"text" : "param knob5_MIDIoffset @max 103 @min 32"
								}

							}
, 							{
								"box" : 								{
									"color" : [ 1.0, 0.419607843137255, 0.141176470588235, 1.0 ],
									"id" : "obj-37",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 827.200019359588623, 436.000010907649994, 276.0, 22.0 ],
									"text" : "param knob3_LFOSpeed @min 0.00001 @max 6."
								}

							}
, 							{
								"box" : 								{
									"color" : [ 1.0, 0.419607843137255, 0.141176470588235, 1.0 ],
									"id" : "obj-32",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 165.866677979628321, 81.800002157688141, 266.0, 22.0 ],
									"text" : "param knob6_bandwidth 0. @min 1. @max 100."
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-4", 0 ],
									"source" : [ "obj-122", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-9", 0 ],
									"source" : [ "obj-123", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"source" : [ "obj-124", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-11", 0 ],
									"source" : [ "obj-125", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-10", 0 ],
									"source" : [ "obj-144", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-12", 0 ],
									"source" : [ "obj-145", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-13", 0 ],
									"source" : [ "obj-146", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-14", 0 ],
									"source" : [ "obj-147", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-19", 0 ],
									"source" : [ "obj-17", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-16", 0 ],
									"source" : [ "obj-19", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-65", 0 ],
									"source" : [ "obj-23", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-86", 1 ],
									"source" : [ "obj-30", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-87", 1 ],
									"source" : [ "obj-31", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-22", 0 ],
									"source" : [ "obj-34", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-44", 0 ],
									"source" : [ "obj-37", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-194", 0 ],
									"source" : [ "obj-39", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-39", 0 ],
									"source" : [ "obj-40", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-42", 0 ],
									"source" : [ "obj-41", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-185", 0 ],
									"source" : [ "obj-42", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-54", 0 ],
									"source" : [ "obj-43", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 0 ],
									"source" : [ "obj-44", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-46", 0 ],
									"source" : [ "obj-45", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-136", 0 ],
									"source" : [ "obj-46", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-48", 0 ],
									"source" : [ "obj-47", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-135", 0 ],
									"source" : [ "obj-48", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-27", 0 ],
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-52", 0 ],
									"source" : [ "obj-50", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-77", 0 ],
									"source" : [ "obj-52", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-55", 0 ],
									"source" : [ "obj-53", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-78", 0 ],
									"source" : [ "obj-55", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-58", 0 ],
									"source" : [ "obj-56", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-80", 0 ],
									"source" : [ "obj-58", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-63", 0 ],
									"source" : [ "obj-59", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-61", 1 ],
									"midpoints" : [ 71.500001728534698, 1026.000024437904358, 193.500001728534698, 1026.000024437904358 ],
									"order" : 0,
									"source" : [ "obj-60", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-61", 0 ],
									"order" : 1,
									"source" : [ "obj-60", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-28", 0 ],
									"source" : [ "obj-61", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-29", 0 ],
									"source" : [ "obj-61", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-126", 0 ],
									"source" : [ "obj-63", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-43", 0 ],
									"source" : [ "obj-65", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-81", 0 ],
									"source" : [ "obj-76", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-60", 0 ],
									"source" : [ "obj-79", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-54", 1 ],
									"source" : [ "obj-81", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-79", 0 ],
									"source" : [ "obj-86", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-79", 0 ],
									"source" : [ "obj-87", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-86", 2 ],
									"order" : 1,
									"source" : [ "obj-88", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-87", 2 ],
									"order" : 0,
									"source" : [ "obj-88", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 211.0, 447.0, 159.0, 22.0 ],
					"saved_object_attributes" : 					{
						"exportfolder" : "C:/github/CCAM-EARTH/silo/",
						"exportname" : "silo"
					}
,
					"text" : "gen~",
					"varname" : "silo"
				}

			}
, 			{
				"box" : 				{
					"attr" : "knob6_bandwidth",
					"id" : "obj-6",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 81.382978141307831, 411.0, 200.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"attr" : "knob2_LFOPhaseOffset",
					"id" : "obj-7",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 81.382978141307831, 298.91490226984024, 150.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"attr" : "knob3_LFOSpeed",
					"id" : "obj-8",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 218.0, 326.51064658164978, 145.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"attr" : "knob4_quantize",
					"id" : "obj-9",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 81.382978141307831, 350.51064658164978, 150.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"attr" : "knob5_MIDIoffset",
					"id" : "obj-10",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 81.382978141307831, 378.702135741710663, 150.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"attr" : "knob1_gateInput",
					"id" : "obj-11",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 81.382978141307831, 232.500000357627869, 150.0, 22.0 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 0 ],
					"source" : [ "obj-1", 11 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"source" : [ "obj-1", 10 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 1 ],
					"order" : 0,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"order" : 1,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 1 ],
					"source" : [ "obj-3", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-39", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"source" : [ "obj-56", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"source" : [ "obj-57", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 0 ],
					"source" : [ "obj-58", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"source" : [ "obj-59", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-10", 0 ],
					"source" : [ "obj-60", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"source" : [ "obj-61", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-7", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-8", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-9", 0 ]
				}

			}
 ],
		"parameters" : 		{
			"obj-17::obj-32" : [ "live.text[2]", "FILTER", 0 ],
			"obj-17::obj-33" : [ "live.text[1]", "FILTER", 0 ],
			"obj-17::obj-34" : [ "live.text[3]", "FILTER", 0 ],
			"obj-3" : [ "live.gain~", "live.gain~", 0 ],
			"obj-56" : [ "BPM", "bandwidth", 0 ],
			"obj-57" : [ "BPM[1]", "lfo offsets", 0 ],
			"obj-58" : [ "BPM[2]", "LFO_hz", 0 ],
			"obj-59" : [ "BPM[3]", "wet/dry", 0 ],
			"obj-60" : [ "BPM[4]", "MIDI Offset", 0 ],
			"obj-61" : [ "BPM[5]", "quantize", 0 ],
			"parameterbanks" : 			{
				"0" : 				{
					"index" : 0,
					"name" : "",
					"parameters" : [ "-", "-", "-", "-", "-", "-", "-", "-" ]
				}

			}
,
			"inherited_shortname" : 1
		}
,
		"dependency_cache" : [ 			{
				"name" : "Tbn-ord-A#1-ff.wav",
				"bootpath" : "~/OneDrive/Documents/Max 8/Library/max patches and sounds 210319_01/trombone_sounds",
				"patcherrelativepath" : "../../../Users/garre/OneDrive/Documents/Max 8/Library/max patches and sounds 210319_01/trombone_sounds",
				"type" : "WAVE",
				"implicit" : 1
			}
, 			{
				"name" : "earth_resonator.gendsp",
				"bootpath" : "C:/github/CCAM-EARTH/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "gDSP",
				"implicit" : 1
			}
, 			{
				"name" : "go.allpass.diffuser.stereo.gendsp",
				"bootpath" : "~/OneDrive/Documents/Max 8/Packages/GeneratingSoundAndOrganizingTime/patchers",
				"patcherrelativepath" : "../../../Users/garre/OneDrive/Documents/Max 8/Packages/GeneratingSoundAndOrganizingTime/patchers",
				"type" : "gDSP",
				"implicit" : 1
			}
, 			{
				"name" : "go_quantize.gendsp",
				"bootpath" : "C:/github/CCAM-EARTH/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "gDSP",
				"implicit" : 1
			}
, 			{
				"name" : "go_unit_sine.gendsp",
				"bootpath" : "C:/github/CCAM-EARTH/patchers",
				"patcherrelativepath" : "../patchers",
				"type" : "gDSP",
				"implicit" : 1
			}
, 			{
				"name" : "oopsy.ctrl.smooth2.gendsp",
				"bootpath" : "~/OneDrive/Documents/Max 8/Packages/oopsy/code",
				"patcherrelativepath" : "../../../Users/garre/OneDrive/Documents/Max 8/Packages/oopsy/code",
				"type" : "gDSP",
				"implicit" : 1
			}
, 			{
				"name" : "oopsy.ctrl.smooth3.gendsp",
				"bootpath" : "~/OneDrive/Documents/Max 8/Packages/oopsy/code",
				"patcherrelativepath" : "../../../Users/garre/OneDrive/Documents/Max 8/Packages/oopsy/code",
				"type" : "gDSP",
				"implicit" : 1
			}
, 			{
				"name" : "oopsy.gate.min.gendsp",
				"bootpath" : "~/OneDrive/Documents/Max 8/Packages/oopsy/code",
				"patcherrelativepath" : "../../../Users/garre/OneDrive/Documents/Max 8/Packages/oopsy/code",
				"type" : "gDSP",
				"implicit" : 1
			}
, 			{
				"name" : "oopsy.gate.trig.gendsp",
				"bootpath" : "~/OneDrive/Documents/Max 8/Packages/oopsy/code",
				"patcherrelativepath" : "../../../Users/garre/OneDrive/Documents/Max 8/Packages/oopsy/code",
				"type" : "gDSP",
				"implicit" : 1
			}
, 			{
				"name" : "oopsy.gate2clock.gendsp",
				"bootpath" : "~/OneDrive/Documents/Max 8/Packages/oopsy/code",
				"patcherrelativepath" : "../../../Users/garre/OneDrive/Documents/Max 8/Packages/oopsy/code",
				"type" : "gDSP",
				"implicit" : 1
			}
, 			{
				"name" : "oopsy.maxpat",
				"bootpath" : "~/OneDrive/Documents/Max 8/Packages/oopsy/patchers",
				"patcherrelativepath" : "../../../Users/garre/OneDrive/Documents/Max 8/Packages/oopsy/patchers",
				"type" : "JSON",
				"implicit" : 1
			}
, 			{
				"name" : "oopsy.node4max.js",
				"bootpath" : "~/OneDrive/Documents/Max 8/Packages/oopsy/javascript",
				"patcherrelativepath" : "../../../Users/garre/OneDrive/Documents/Max 8/Packages/oopsy/javascript",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "oopsy.snoop.js",
				"bootpath" : "~/OneDrive/Documents/Max 8/Packages/oopsy/javascript",
				"patcherrelativepath" : "../../../Users/garre/OneDrive/Documents/Max 8/Packages/oopsy/javascript",
				"type" : "TEXT",
				"implicit" : 1
			}
, 			{
				"name" : "oopsy.suggestions.gendsp",
				"bootpath" : "~/OneDrive/Documents/Max 8/Packages/oopsy/code",
				"patcherrelativepath" : "../../../Users/garre/OneDrive/Documents/Max 8/Packages/oopsy/code",
				"type" : "gDSP",
				"implicit" : 1
			}
 ],
		"autosave" : 0,
		"styles" : [ 			{
				"name" : "MP-M4L",
				"default" : 				{
					"accentcolor" : [ 0.411764705882353, 0.411764705882353, 0.411764705882353, 1.0 ],
					"bgcolor" : [ 0.098039215686275, 0.098039215686275, 0.098039215686275, 1.0 ],
					"bgfillcolor" : 					{
						"color" : [ 0.266666666666667, 0.266666666666667, 0.266666666666667, 1.0 ],
						"color1" : [ 0.376470588235294, 0.384313725490196, 0.4, 1.0 ],
						"color2" : [ 0.290196078431373, 0.309803921568627, 0.301960784313725, 1.0 ],
						"dynamiccolor" : [ 0.266666666666667, 0.266666666666667, 0.266666666666667, 1.0, "live_contrast_frame", 1, 0.266666666666667, 0.266666666666667, 0.266666666666667, 1.0, "Control Border" ],
						"type" : "color"
					}
,
					"color" : [ 0.333333333333333, 0.870588235294118, 0.964705882352941, 1.0 ],
					"editing_bgcolor" : [ 0.56078431372549, 0.56078431372549, 0.56078431372549, 1.0 ],
					"elementcolor" : [ 0.313725490196078, 0.313725490196078, 0.313725490196078, 1.0 ],
					"locked_bgcolor" : [ 0.56078431372549, 0.56078431372549, 0.56078431372549, 1.0 ],
					"patchlinecolor" : [ 0.313725490196078, 0.313725490196078, 0.313725490196078, 1.0 ],
					"selectioncolor" : [ 1.0, 0.694117647058824, 0.0, 1.0 ],
					"stripecolor" : [ 0.313725490196078, 0.313725490196078, 0.313725490196078, 1.0 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ]
				}
,
				"parentstyle" : "",
				"multi" : 0
			}
, 			{
				"name" : "rnbodefault",
				"default" : 				{
					"accentcolor" : [ 0.343034118413925, 0.506230533123016, 0.86220508813858, 1.0 ],
					"bgcolor" : [ 0.031372549019608, 0.125490196078431, 0.211764705882353, 1.0 ],
					"bgfillcolor" : 					{
						"angle" : 270.0,
						"autogradient" : 0.0,
						"color" : [ 0.031372549019608, 0.125490196078431, 0.211764705882353, 1.0 ],
						"color1" : [ 0.031372549019608, 0.125490196078431, 0.211764705882353, 1.0 ],
						"color2" : [ 0.263682, 0.004541, 0.038797, 1.0 ],
						"proportion" : 0.39,
						"type" : "color"
					}
,
					"color" : [ 0.929412, 0.929412, 0.352941, 1.0 ],
					"elementcolor" : [ 0.357540726661682, 0.515565991401672, 0.861786782741547, 1.0 ],
					"fontname" : [ "Lato" ],
					"fontsize" : [ 12.0 ],
					"stripecolor" : [ 0.258338063955307, 0.352425158023834, 0.511919498443604, 1.0 ],
					"textcolor_inverse" : [ 0.968627, 0.968627, 0.968627, 1 ]
				}
,
				"parentstyle" : "",
				"multi" : 0
			}
 ]
	}

}
