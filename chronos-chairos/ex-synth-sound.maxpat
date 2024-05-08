{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 8,
			"minor" : 5,
			"revision" : 6,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 659.0, 241.0, 1209.0, 802.0 ],
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
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-17",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"patching_rect" : [ 429.0, 109.0, 29.5, 22.0 ],
					"text" : "- 48"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-15",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 480.66666978597641, -41.999998390674591, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-43",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 9.583333998918533, -67.333333432674408, 150.0, 48.0 ],
					"text" : "0 = even, \n0.5 mix,\n1 = odd"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-26",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 525.333337068557739, 115.666670739650726, 50.0, 22.0 ],
					"text" : "65"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-24",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"patching_rect" : [ 430.66666978597641, 22.666669011116028, 59.0, 22.0 ],
					"text" : "random 7"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-23",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 430.66666978597641, 53.666666269302368, 189.0, 22.0 ],
					"text" : "zl.lookup 60 62 63 65 67 69 70 72"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-21",
					"maxclass" : "kslider",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "int", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 426.66666978597641, 166.99999988079071, 336.0, 53.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-18",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 430.66666978597641, -37.333333432674408, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-11",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 430.66666978597641, -10.0, 69.0, 22.0 ],
					"text" : "metro 1000"
				}

			}
, 			{
				"box" : 				{
					"domain" : [ 0.0, 4000.0 ],
					"id" : "obj-22",
					"maxclass" : "spectroscope~",
					"monochrome" : 0,
					"numinlets" : 2,
					"numoutlets" : 1,
					"orientation" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 548.499977588653564, 246.0, 427.0, 327.0 ],
					"range" : [ 0.0, 1.0 ],
					"scroll" : 1,
					"sono" : 1
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-10",
					"maxclass" : "spectroscope~",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 216.166664958000183, 272.0, 300.0, 100.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-14",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 128.5, 182.49999988079071, 39.0, 22.0 ],
					"text" : "click~"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-13",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 128.5, 147.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-7",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 131.0, 424.0, 45.0, 45.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-6",
					"lastchannelcount" : 0,
					"maxclass" : "live.gain~",
					"numinlets" : 2,
					"numoutlets" : 5,
					"outlettype" : [ "signal", "signal", "", "float", "list" ],
					"parameter_enable" : 1,
					"patching_rect" : [ 128.5, 254.0, 48.0, 136.0 ],
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
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 8,
							"minor" : 5,
							"revision" : 6,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"classnamespace" : "dsp.gen",
						"rect" : [ 542.0, 540.0, 1734.0, 1178.0 ],
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
									"id" : "obj-11",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1398.333382606506348, 29.0, 284.0, 22.0 ],
									"text" : "param spectralSpread @min 0 @max 1 @ default 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-80",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1076.666698753833771, 231.333340227603912, 40.0, 22.0 ],
									"text" : "mix"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-78",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1054.600006222724915, 133.06667572259903, 71.999997675418854, 20.0 ],
									"text" : "0.5 = mix"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-76",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1054.600006222724915, 155.06667572259903, 71.999997675418854, 20.0 ],
									"text" : "1 = odd"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-77",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1054.600006222724915, 106.666669845581055, 71.999997675418854, 20.0 ],
									"text" : "0 = even"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-75",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 987.933341681957245, 36.266671180725098, 239.0, 22.0 ],
									"text" : "param partials @min 0 @max 1 @default 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-73",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 872.266667902469635, 109.466667950153351, 71.999997675418854, 20.0 ],
									"text" : "log"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-72",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 872.266667902469635, 86.399996161460876, 71.999997675418854, 20.0 ],
									"text" : "linear"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-70",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 666.266665577888489, 64.0, 285.0, 22.0 ],
									"text" : "param spectralFalloff @min 0.1 @max 5 @default 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-69",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1546.333336234092712, 654.000019490718842, 53.0, 22.0 ],
									"text" : "in 2 midi"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-66",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1534.666712403297424, 694.000020682811737, 32.0, 22.0 ],
									"text" : "mtof"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-63",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 666.266665577888489, 36.266671180725098, 289.0, 22.0 ],
									"text" : "param spectralDensity @min 1 @max 32 @default 8"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-60",
									"linecount" : 20,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1430.0, 989.0, 2448.0, 282.0 ],
									"text" : "\n// get current sum of active voices\nnumOn = 0;\nfor(i = 0; i<numvoice;i+=1){\n\tnumOn += onoff.peek(0,i);\n\t}\nout1 = numOn;\n\ntotal = 0;\t\t\t\t\nfor(i=1023; i>0;i=i-1){\nlast = activeHistory.peek(i,0);\nactiveHistory.poke(last,i-1,0);\ntotal += last;\n}\t\nactiveHistory.poke(numOn,1023,0);\ntotal += numOn;\n\navg = total / 1024;\nactiveAvg.poke(avg,0,0);\t\n\t\t\t"
								}

							}
, 							{
								"box" : 								{
									"code" : "for(s =0;s<spectralDensity;s+=1){\r\n\t\r\n\tspectra.poke(spectralSpread*((s+1)*2),0,s); \r\n\t}",
									"fontface" : 0,
									"fontname" : "<Monospaced>",
									"fontsize" : 12.0,
									"id" : "obj-54",
									"maxclass" : "codebox",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1269.0, 110.0, 356.0, 185.0 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-53",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 1269.0, 64.0, 101.0, 22.0 ],
									"text" : "data spectra 1 32"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-51",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1650.333382606506348, 672.666686713695526, 32.0, 22.0 ],
									"text" : "mtof"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-49",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1726.666717529296875, 608.000018119812012, 29.0, 22.0 ],
									"text" : "- 24"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-48",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1653.333382606506348, 604.000018000602722, 36.0, 22.0 ],
									"text" : "> 0.5"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-47",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1650.333382606506348, 644.000019192695618, 95.333334922790527, 22.0 ],
									"text" : "switch"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-46",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1653.333382606506348, 574.000017106533051, 80.666668057441711, 22.0 ],
									"text" : "latch"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-45",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1653.333382606506348, 539.333349406719208, 37.0, 22.0 ],
									"text" : "noise"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-44",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1348.000043392181396, 346.000025153160095, 150.0, 34.0 ],
									"text" : "frequency.poke(50*((i+1)*2),0,i); "
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-42",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1425.000047504901886, 654.000019490718842, 65.0, 22.0 ],
									"text" : "in 1 trigger"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-28",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1723.000008165836334, 506.200000762939453, 53.0, 22.0 ],
									"text" : "in 2 midi"
								}

							}
, 							{
								"box" : 								{
									"code" : "output = 0;\r\n\r\n// updating ramp;\r\nfor(i = 0;i<numvoice;i+=1){\r\n\to = onoff.peek(0,i);\r\n\tif(o==1){\r\n\t\r\n\t// determine spectral\r\n\t\r\n\tfor(s = 0;s<spectralDensity;s+=1){\r\n        falloff = spectralFalloff - (s/spectralDensity);\r\n\t\twave = 0;\r\n\t\tr = ramp.peek(s,i);\r\n\t\tval = r*2*pi;\r\n\t\twave = sin(val);\r\n\t\tamp = envAmps.peek(0,i); \r\n        amp *= falloff;\r\n\t\t\r\n\t\tif(s>0){\r\n \t\t\tif(s%2==0){\r\n\t\t\t\tamp*= mix(0,1,partials);\r\n\t\t\t}\r\n\t\t\telse{\r\n\t\t\t\tamp*= mix(1,0,partials);\r\n\t\t\t}\r\n               }\r\n        wave *= amp;\r\n\t\twave /= spectralDensity;\r\n\t\toutput += wave;\r\n\t\t\r\n\r\n\t\t}\t\r\n\t}\r\n}\r\n\r\noutput /= numvoice;\r\nout1 = output;\r\n\r\n\r\n",
									"fontface" : 0,
									"fontname" : "<Monospaced>",
									"fontsize" : 12.0,
									"id" : "obj-4",
									"maxclass" : "codebox",
									"numinlets" : 1,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 24.500001668930054, 145.200001776218414, 339.0, 245.999999284744263 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-21",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 232.166676074266434, 86.399996161460876, 228.400001168251038, 20.0 ],
									"text" : "oscillation ramp completion (linear 0-1)"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-19",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 232.566676080226898, 38.0, 227.600001156330109, 48.0 ],
									"text" : "frequency of oscillators (0-20000) hz\nchannel is a voice\neach position is spectral component"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-12",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 936.333322823047638, 488.799995601177216, 237.200001299381256, 20.0 ],
									"text" : "polyphonic voice management (0 or 1)"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-10",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 947.733343124389648, 535.800002455711365, 237.200001299381256, 20.0 ],
									"text" : "polyphonic envelope ramps (linear 0->1)"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-9",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 947.733343124389648, 511.800002455711365, 272.40000182390213, 20.0 ],
									"text" : "polyphonic envelope amplitudes (0 -> 1 -> 0)"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-22",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1246.833334147930145, 588.400007367134094, 97.0, 22.0 ],
									"text" : "param numvoice"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-20",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1357.633346974849701, 588.400007367134094, 265.0, 22.0 ],
									"text" : "param numvoice @min 1 @max 32 @default 16"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-13",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 382.600005447864532, 114.800001442432404, 174.0, 20.0 ],
									"text" : "increment ramps"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-68",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 24.500001668930054, 427.799998700618744, 35.0, 22.0 ],
									"text" : "out 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-67",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 973.333330690860748, 609.800002753734589, 181.0, 34.0 ],
									"text" : "poly accumlate envelope ramps and sample envelope"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-65",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 825.266665577888489, 601.80000227689743, 111.0, 22.0 ],
									"text" : "data durations 1 32"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-64",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 825.266665577888489, 572.800002753734589, 119.0, 22.0 ],
									"text" : "data envRamps 1 32"
								}

							}
, 							{
								"box" : 								{
									"code" : "if(in1>0){\r\n\t// grab current envelope;\t\r\n\tfor(i = 0; i<512;i+=1){\r\n\tsamp = envelope.peek(i,0);\r\n\tenvelopes.poke(samp,i,in2);\r\n }\r\n\t// store length information in samples\r\n\tlength = attack+sustain+decay;\r\n\tlength = (length / 1000)*samplerate;\r\n\tdurations.poke(length,0,in2);\r\n\t\r\n//\t reset accumulation buffer for targeted voice\r\n\tenvRamps.poke(0,0,in2);\r\n     // turn voice on\r\n\tonoff.poke(1,0,in2);\r\n\r\n}\r\n\r\n// increment accums buffers. \r\n// flip voice off if it's above length;\r\n//voicecount = 0;\r\nfor(i = 0; i<numvoice;i+=1){\r\n\t\r\nstate = onoff.peek(0,i);\r\n\r\n    if(state == 1){\r\n\tlen = durations.peek(0,i);\r\n\tinc = 1 / len;\r\n\told = envRamps.peek(0,i);\r\n\tnewInc = old+inc;\r\n\tenvRamps.poke(newInc,0,i); \r\n  if(newInc>1){\r\n    onoff.poke(0,0,i);\r\n\t}\r\n\telse {\r\n    amp = envelopes.sample(newInc,i);\r\n    envAmps.poke(amp,0,i);\r\n    }\r\n\r\n\t\r\n}\r\n   \r\n}\r\n\r\n\r\n",
									"fontface" : 0,
									"fontname" : "<Monospaced>",
									"fontsize" : 12.0,
									"id" : "obj-59",
									"maxclass" : "codebox",
									"numinlets" : 2,
									"numoutlets" : 0,
									"patching_rect" : [ 789.833332061767578, 666.000010848045349, 420.000001728534698, 442.200001835823059 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-58",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1190.833333790302277, 622.600002527236938, 75.000000357627869, 22.0 ],
									"text" : "wrap"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-57",
									"maxclass" : "newobj",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1190.833333790302277, 588.400007367134094, 51.0, 22.0 ],
									"text" : "accum"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-56",
									"linecount" : 3,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 973.333330690860748, 559.800002753734589, 150.0, 48.0 ],
									"text" : "when new trig, bank current envelope and length (in samples)"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-52",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 391.700007140636444, 639.366672992706299, 117.0, 22.0 ],
									"text" : "data envelope 512 1"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-31",
									"linecount" : 2,
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 391.700007140636444, 595.80000227689743, 342.000002861022949, 34.0 ],
									"text" : "envelope calculation from envelope params --> [data envelope]"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-7",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 391.700007140636444, 481.000000834465027, 276.0, 22.0 ],
									"text" : "param attack @min 1. @max 20000 @default 100"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-3",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 391.700007140636444, 560.60000067949295, 283.0, 22.0 ],
									"text" : "param release @min 1. @max 20000 @default 100"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-2",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 391.700007140636444, 532.60000067949295, 276.0, 22.0 ],
									"text" : "param decay @min 1. @max 20000 @default 100"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-1",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 391.700007140636444, 506.200000762939453, 255.0, 22.0 ],
									"text" : "param sustain @min 0. @max 1. @default 0.5"
								}

							}
, 							{
								"box" : 								{
									"code" : "count = 0;\r\nval=0;\r\ndur = attack + decay + release;\r\nlength = dim(envelope);\r\n\r\nattackNorm = (attack/dur)*length; \r\ndecayNorm =  (decay/dur )*length;\r\nreleaseNorm = (release/dur)*length;\r\n\r\nattackInt = 1 / attackNorm;\r\ndecayInt = (1-sustain) / decayNorm;\r\nreleaseInt = sustain / releaseNorm;\r\n\r\nfor(i = 0; i<attackNorm;i+=1){\r\n\tval+=attackInt;\r\n\tenvelope.poke(val,count);\r\n\tcount+=1;\r\n}\r\n\r\nfor(i = 0; i<decayNorm;i+=1){\r\n\tval-=decayInt;\r\n\tenvelope.poke(val,count);\r\n\tcount+=1;\r\n}\r\n\r\nfor(i = 0; i<releaseNorm;i+=1){\r\n\tval-=releaseInt;\r\n\tenvelope.poke(val,count);\r\n\tcount+=1;\r\n}\r\n",
									"fontface" : 0,
									"fontname" : "<Monospaced>",
									"fontsize" : 12.0,
									"id" : "obj-27",
									"maxclass" : "codebox",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 16.500001549720764, 470.999999403953552, 347.00000011920929, 440.466669261455536 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-26",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 825.266665577888489, 629.80000227689743, 130.0, 22.0 ],
									"text" : "data envelopes 512 32"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-25",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 825.266665577888489, 516.466663122177124, 88.0, 22.0 ],
									"text" : "data onoff 1 32"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-24",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 789.833332061767578, 455.200003623962402, 65.0, 22.0 ],
									"text" : "in 1 trigger"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-23",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 825.266665577888489, 544.466669380664825, 112.0, 22.0 ],
									"text" : "data envAmps 1 32"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-18",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 24.500001668930054, 114.800001442432404, 269.200001418590546, 20.0 ],
									"text" : "polyphasor sinusoidal oscillator"
								}

							}
, 							{
								"box" : 								{
									"code" : "rampUp(hz,amp){\r\n\tint = hz/samplerate;\r\n\tnewAmp = amp + int;\r\n\tnewAmp = wrap(newAmp,0,1);\r\n\treturn newAmp;\r\n}\r\n\r\noutput = 0;\r\n// updating ramp;\r\nfor(i = 0;i<numvoice;i+=1){\r\n\to = onoff.peek(0,i);\r\n\tif(o==1){\t\r\n\t\t//calculate fundamental\t\r\n\t\tfundHz = frequency.peek(0,i); //fundamental frequency\r\n\t\tamp = ramp.peek(0,i);\r\n\t    newAmp = rampUp(fundHz,amp);\r\n     \tramp.poke(newAmp,0,i);\r\n\t\t// ramp spectra\r\n\t    for (s = 1;s<spectralDensity+1;s+=1){\r\n        \tsHz = fundHz*(s)*2*spectralSpread;\r\n\t\t\tsAmp = ramp.peek(s,i);\r\n\t\t\tnewsAmp = rampUp(sHz,sAmp);\r\n        \tramp.poke(newsAmp,s,i);\r\n        \t}\r\n    }\t\r\n\t}\r\n\r\n\t\r\n\t\r\n\r\n\t//output += finalAmp;",
									"fontface" : 0,
									"fontname" : "<Monospaced>",
									"fontsize" : 12.0,
									"id" : "obj-17",
									"maxclass" : "codebox",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 386.600005567073822, 145.200001776218414, 610.333341419696808, 259.999999701976776 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-16",
									"maxclass" : "comment",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 1370.033343017101288, 628.000007033348083, 183.0, 20.0 ],
									"text" : "initialize arbitrary frequency"
								}

							}
, 							{
								"box" : 								{
									"code" : "voice = in1;\r\ntrig = in2; \r\nfq = in3; \r\n\r\nif(trig){\r\n frequency.poke(fq,0,voice); \r\n}\r\n\r\n",
									"fontface" : 0,
									"fontname" : "<Monospaced>",
									"fontsize" : 12.0,
									"id" : "obj-8",
									"maxclass" : "codebox",
									"numinlets" : 3,
									"numoutlets" : 0,
									"patching_rect" : [ 1256.000047504901886, 732.533352196216583, 357.0, 134.0 ]
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-6",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 26.500001668930054, 85.399996161460876, 121.0, 22.0 ],
									"text" : "data ramp 32 32"
								}

							}
, 							{
								"box" : 								{
									"id" : "obj-5",
									"maxclass" : "newobj",
									"numinlets" : 0,
									"numoutlets" : 2,
									"outlettype" : [ "", "" ],
									"patching_rect" : [ 26.500001668930054, 56.199996113777161, 121.0, 22.0 ],
									"text" : "data frequency 32 32"
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-58", 2 ],
									"source" : [ "obj-22", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-57", 0 ],
									"order" : 0,
									"source" : [ "obj-24", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-59", 0 ],
									"order" : 1,
									"source" : [ "obj-24", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-47", 1 ],
									"order" : 1,
									"source" : [ "obj-28", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-49", 0 ],
									"order" : 0,
									"source" : [ "obj-28", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-68", 0 ],
									"source" : [ "obj-4", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-46", 1 ],
									"order" : 0,
									"source" : [ "obj-42", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 1 ],
									"order" : 1,
									"source" : [ "obj-42", 0 ]
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
									"destination" : [ "obj-48", 0 ],
									"source" : [ "obj-46", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-51", 0 ],
									"source" : [ "obj-47", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-47", 0 ],
									"source" : [ "obj-48", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-47", 2 ],
									"source" : [ "obj-49", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-58", 0 ],
									"source" : [ "obj-57", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-59", 1 ],
									"order" : 1,
									"source" : [ "obj-58", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 0 ],
									"order" : 0,
									"source" : [ "obj-58", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-8", 2 ],
									"source" : [ "obj-66", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-66", 0 ],
									"source" : [ "obj-69", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 128.5, 226.666667282581329, 317.16666978597641, 22.0 ],
					"text" : "gen~"
				}

			}
, 			{
				"box" : 				{
					"attr" : "attack",
					"id" : "obj-4",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 17.5, 13.333335041999817, 150.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"attr" : "decay",
					"id" : "obj-5",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 17.5, 35.666666269302368, 150.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"attr" : "release",
					"id" : "obj-8",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 17.5, 59.666666269302368, 150.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"attr" : "numvoice",
					"id" : "obj-9",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 17.5, 83.666666269302368, 150.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"attr" : "spectralDensity",
					"id" : "obj-31",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 17.5, 108.49999988079071, 150.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"attr" : "partials",
					"id" : "obj-32",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 17.5, -10.666664958000183, 150.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"attr" : "spectralSpread",
					"id" : "obj-2",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 191.5, 67.66666699999999, 150.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"attr" : "partials",
					"id" : "obj-3",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 237.5, 125.66666699999999, 150.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"attr" : "spectralFalloff",
					"id" : "obj-12",
					"maxclass" : "attrui",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 173.5, 193.66666699999999, 150.0, 22.0 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-10", 0 ],
					"order" : 1,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"order" : 0,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 1 ],
					"order" : 2,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"order" : 3,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 0 ],
					"source" : [ "obj-13", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 1 ],
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-21", 0 ],
					"source" : [ "obj-17", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 1 ],
					"order" : 0,
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 0 ],
					"order" : 1,
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 0 ],
					"order" : 1,
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 1 ],
					"order" : 0,
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-32", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 1 ],
					"source" : [ "obj-6", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"source" : [ "obj-6", 0 ]
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
			"obj-6" : [ "live.gain~", "live.gain~", 0 ],
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
		"dependency_cache" : [  ],
		"autosave" : 0
	}

}
