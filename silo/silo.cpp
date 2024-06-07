#include "silo.h"

namespace silo {

/****************************************************************************************
Copyright (c) 2023 Cycling '74

The code that Max generates automatically and that end users are capable of
exporting and using, and any associated documentation files (the “Software”)
is a work of authorship for which Cycling '74 is the author and owner for
copyright purposes.

This Software is dual-licensed either under the terms of the Cycling '74
License for Max-Generated Code for Export, or alternatively under the terms
of the General Public License (GPL) Version 3. You may use the Software
according to either of these licenses as it is most appropriate for your
project on a case-by-case basis (proprietary or not).

A) Cycling '74 License for Max-Generated Code for Export

A license is hereby granted, free of charge, to any person obtaining a copy
of the Software (“Licensee”) to use, copy, modify, merge, publish, and
distribute copies of the Software, and to permit persons to whom the Software
is furnished to do so, subject to the following conditions:

The Software is licensed to Licensee for all uses that do not include the sale,
sublicensing, or commercial distribution of software that incorporates this
source code. This means that the Licensee is free to use this software for
educational, research, and prototyping purposes, to create musical or other
creative works with software that incorporates this source code, or any other
use that does not constitute selling software that makes use of this source
code. Commercial distribution also includes the packaging of free software with
other paid software, hardware, or software-provided commercial services.

For entities with UNDER 200k USD in annual revenue or funding, a license is hereby
granted, free of charge, for the sale, sublicensing, or commercial distribution
of software that incorporates this source code, for as long as the entity's
annual revenue remains below 200k USD annual revenue or funding.

For entities with OVER 200k USD in annual revenue or funding interested in the
sale, sublicensing, or commercial distribution of software that incorporates
this source code, please send inquiries to licensing (at) cycling74.com.

The above copyright notice and this license shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Please see
https://support.cycling74.com/hc/en-us/articles/360050779193-Gen-Code-Export-Licensing-FAQ
for additional information

B) General Public License Version 3 (GPLv3)
Details of the GPLv3 license can be found at: https://www.gnu.org/licenses/gpl-3.0.html
****************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	Change __m_change_41;
	Change __m_change_49;
	Change __m_change_664;
	Change __m_change_40;
	Change __m_change_48;
	Change __m_change_38;
	Change __m_change_42;
	Change __m_change_39;
	Change __m_change_668;
	Change __m_change_665;
	Data m_fqs_37;
	Data m_noise_33;
	Data m_amps_32;
	Data m_bws_27;
	Delay m_delay_5;
	Delay m_delay_4;
	Delay m_delay_8;
	Delay m_delay_6;
	Delay m_delay_7;
	Delay m_delay_9;
	Delay m_delay_11;
	Delay m_delay_10;
	Phasor __m_phasor_667;
	PlusEquals __m_pluseq_675;
	int vectorsize;
	int __exception;
	int __loopcount;
	t_sample __m_slide_461;
	t_sample m_y_460;
	t_sample m_y_441;
	t_sample __m_slide_429;
	t_sample m_history_439;
	t_sample m_history_440;
	t_sample m_history_438;
	t_sample __m_slide_448;
	t_sample __m_slide_445;
	t_sample m_y_437;
	t_sample m_history_457;
	t_sample m_y_456;
	t_sample __m_slide_432;
	t_sample __m_slide_442;
	t_sample m_history_459;
	t_sample m_history_458;
	t_sample __m_slide_451;
	t_sample m_history_476;
	t_sample __m_slide_467;
	t_sample m_history_497;
	t_sample m_history_496;
	t_sample m_history_495;
	t_sample m_y_494;
	t_sample m_y_498;
	t_sample __m_slide_502;
	t_sample __m_slide_499;
	t_sample __m_slide_505;
	t_sample __m_slide_464;
	t_sample __m_slide_489;
	t_sample __m_slide_483;
	t_sample __m_slide_426;
	t_sample m_y_475;
	t_sample __m_slide_470;
	t_sample __m_slide_486;
	t_sample m_history_477;
	t_sample m_y_479;
	t_sample m_history_478;
	t_sample __m_slide_480;
	t_sample __m_slide_423;
	t_sample m_history_400;
	t_sample m_history_421;
	t_sample __m_slide_366;
	t_sample m_y_365;
	t_sample m_history_364;
	t_sample __m_slide_369;
	t_sample __m_slide_375;
	t_sample __m_slide_372;
	t_sample m_y_380;
	t_sample m_history_381;
	t_sample m_history_363;
	t_sample m_y_361;
	t_sample m_y_346;
	t_sample m_history_345;
	t_sample m_history_362;
	t_sample __m_slide_347;
	t_sample __m_slide_353;
	t_sample __m_slide_350;
	t_sample __m_slide_356;
	t_sample m_y_422;
	t_sample m_history_382;
	t_sample m_y_384;
	t_sample __m_slide_410;
	t_sample __m_slide_407;
	t_sample __m_slide_404;
	t_sample __m_slide_413;
	t_sample m_history_419;
	t_sample m_y_418;
	t_sample m_history_420;
	t_sample m_history_383;
	t_sample m_y_403;
	t_sample m_history_401;
	t_sample __m_slide_388;
	t_sample __m_slide_385;
	t_sample m_history_402;
	t_sample __m_slide_391;
	t_sample m_y_399;
	t_sample __m_slide_394;
	t_sample __m_slide_508;
	t_sample m_y_513;
	t_sample m_y_536;
	t_sample m_history_515;
	t_sample m_history_628;
	t_sample m_y_627;
	t_sample __m_slide_622;
	t_sample __m_slide_619;
	t_sample m_history_629;
	t_sample m_y_631;
	t_sample m_history_630;
	t_sample __m_slide_632;
	t_sample __m_slide_635;
	t_sample __m_slide_616;
	t_sample m_y_612;
	t_sample __m_slide_603;
	t_sample __m_slide_600;
	t_sample __m_slide_613;
	t_sample m_y_608;
	t_sample m_history_610;
	t_sample m_history_609;
	t_sample m_history_611;
	t_sample __m_slide_597;
	t_sample __m_slide_638;
	t_sample m_y_646;
	t_sample __m_latch_670;
	t_sample __m_latch_669;
	t_sample samples_to_seconds;
	t_sample __m_latch_671;
	t_sample __m_latch_673;
	t_sample __m_latch_672;
	t_sample __m_latch_674;
	t_sample __m_slide_641;
	t_sample elapsed;
	t_sample __m_slide_657;
	t_sample m_history_648;
	t_sample m_history_647;
	t_sample __m_slide_660;
	t_sample m_history_649;
	t_sample __m_slide_651;
	t_sample m_y_650;
	t_sample __m_slide_654;
	t_sample m_history_514;
	t_sample __m_slide_594;
	t_sample m_history_592;
	t_sample __m_slide_537;
	t_sample m_history_344;
	t_sample m_history_535;
	t_sample __m_slide_540;
	t_sample __m_slide_546;
	t_sample __m_slide_543;
	t_sample m_y_551;
	t_sample m_history_552;
	t_sample m_history_534;
	t_sample m_y_532;
	t_sample m_y_517;
	t_sample m_history_516;
	t_sample m_history_533;
	t_sample __m_slide_518;
	t_sample __m_slide_524;
	t_sample __m_slide_521;
	t_sample __m_slide_527;
	t_sample m_y_593;
	t_sample m_history_553;
	t_sample m_y_555;
	t_sample __m_slide_581;
	t_sample __m_slide_578;
	t_sample __m_slide_575;
	t_sample __m_slide_584;
	t_sample m_history_590;
	t_sample m_y_589;
	t_sample m_history_591;
	t_sample m_history_554;
	t_sample m_y_574;
	t_sample m_history_572;
	t_sample __m_slide_559;
	t_sample __m_slide_556;
	t_sample m_history_573;
	t_sample __m_slide_562;
	t_sample m_y_570;
	t_sample __m_slide_565;
	t_sample m_history_571;
	t_sample m_history_343;
	t_sample m_y_323;
	t_sample __m_slide_337;
	t_sample __m_slide_103;
	t_sample __m_slide_100;
	t_sample m_y_99;
	t_sample m_history_98;
	t_sample __m_slide_106;
	t_sample m_y_114;
	t_sample __m_slide_109;
	t_sample m_history_115;
	t_sample m_history_116;
	t_sample m_history_97;
	t_sample m_y_95;
	t_sample m_y_80;
	t_sample m_history_79;
	t_sample m_history_96;
	t_sample __m_slide_81;
	t_sample __m_slide_87;
	t_sample __m_slide_84;
	t_sample __m_slide_90;
	t_sample m_history_78;
	t_sample m_history_117;
	t_sample __m_slide_119;
	t_sample m_y_152;
	t_sample __m_slide_147;
	t_sample __m_slide_144;
	t_sample __m_slide_141;
	t_sample m_history_153;
	t_sample m_history_155;
	t_sample m_history_154;
	t_sample m_y_156;
	t_sample m_y_118;
	t_sample __m_slide_138;
	t_sample m_history_136;
	t_sample __m_slide_125;
	t_sample __m_slide_122;
	t_sample m_y_137;
	t_sample __m_slide_128;
	t_sample m_history_134;
	t_sample m_y_133;
	t_sample m_history_135;
	t_sample __m_slide_157;
	t_sample m_history_77;
	t_sample __m_slide_71;
	t_sample m_sw_20;
	t_sample m_gate_19;
	t_sample m_cvin_18;
	t_sample m_history_17;
	t_sample m_sw_21;
	t_sample m_sw_23;
	t_sample m_sw_22;
	t_sample m_knob6_wetdry_24;
	t_sample m_sw_25;
	t_sample m_history_16;
	t_sample m_history_14;
	t_sample m_history_1;
	t_sample samplerate;
	t_sample m_history_15;
	t_sample m_history_2;
	t_sample m_history_12;
	t_sample m_history_3;
	t_sample m_history_13;
	t_sample m_y_76;
	t_sample m_sw_26;
	t_sample m_sw_29;
	t_sample m_history_60;
	t_sample m_history_59;
	t_sample m_history_58;
	t_sample m_y_57;
	t_sample m_y_61;
	t_sample __m_slide_65;
	t_sample __m_slide_62;
	t_sample __m_slide_68;
	t_sample m_knob2_amps_28;
	t_sample __m_carry_52;
	t_sample __m_carry_45;
	t_sample m_knob_31;
	t_sample m_knob4_voices_30;
	t_sample __m_count_50;
	t_sample m_knob5_MIDIoffset_34;
	t_sample m_sw_36;
	t_sample m_knob_35;
	t_sample __m_count_43;
	t_sample m_y_342;
	t_sample __m_slide_160;
	t_sample __m_slide_166;
	t_sample m_y_285;
	t_sample __m_slide_280;
	t_sample __m_slide_277;
	t_sample __m_slide_274;
	t_sample m_history_286;
	t_sample m_history_288;
	t_sample m_history_287;
	t_sample m_y_289;
	t_sample __m_slide_290;
	t_sample __m_slide_271;
	t_sample m_history_269;
	t_sample __m_slide_258;
	t_sample __m_slide_255;
	t_sample m_y_270;
	t_sample __m_slide_261;
	t_sample m_history_267;
	t_sample m_y_266;
	t_sample m_history_268;
	t_sample __m_slide_252;
	t_sample __m_slide_293;
	t_sample __m_slide_299;
	t_sample m_history_326;
	t_sample m_history_325;
	t_sample m_history_324;
	t_sample __m_count_677;
	t_sample m_y_327;
	t_sample __m_slide_331;
	t_sample __m_slide_328;
	t_sample __m_slide_334;
	t_sample __m_slide_296;
	t_sample __m_slide_318;
	t_sample __m_slide_312;
	t_sample m_history_305;
	t_sample m_y_304;
	t_sample __m_slide_315;
	t_sample m_history_306;
	t_sample m_y_308;
	t_sample m_history_307;
	t_sample __m_slide_309;
	t_sample __m_slide_163;
	t_sample m_y_251;
	t_sample m_history_249;
	t_sample m_history_193;
	t_sample m_history_192;
	t_sample m_history_191;
	t_sample m_y_190;
	t_sample m_y_194;
	t_sample __m_slide_198;
	t_sample __m_slide_195;
	t_sample __m_slide_201;
	t_sample __m_slide_204;
	t_sample __m_slide_185;
	t_sample __m_slide_179;
	t_sample m_history_172;
	t_sample m_y_171;
	t_sample __m_slide_182;
	t_sample m_history_173;
	t_sample m_y_175;
	t_sample m_history_174;
	t_sample __m_slide_176;
	t_sample m_history_250;
	t_sample m_y_209;
	t_sample m_history_211;
	t_sample __m_slide_236;
	t_sample __m_slide_233;
	t_sample m_y_232;
	t_sample m_history_231;
	t_sample __m_slide_239;
	t_sample m_y_247;
	t_sample __m_slide_242;
	t_sample m_history_248;
	t_sample m_history_210;
	t_sample m_history_230;
	t_sample m_y_228;
	t_sample m_y_213;
	t_sample m_history_212;
	t_sample m_history_229;
	t_sample __m_slide_214;
	t_sample __m_slide_220;
	t_sample __m_slide_217;
	t_sample __m_slide_223;
	t_sample __m_carry_679;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_delay_4.reset("m_delay_4", ((int)3469));
		m_delay_5.reset("m_delay_5", ((int)5419));
		m_delay_6.reset("m_delay_6", ((int)5167));
		m_delay_7.reset("m_delay_7", ((int)7351));
		m_delay_8.reset("m_delay_8", ((int)2791));
		m_delay_9.reset("m_delay_9", ((int)4447));
		m_delay_10.reset("m_delay_10", ((int)3571));
		m_delay_11.reset("m_delay_11", ((int)8269));
		m_history_12 = ((int)0);
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
		m_history_17 = ((int)0);
		m_cvin_18 = ((int)0);
		m_gate_19 = ((int)0);
		m_sw_20 = ((int)0);
		m_sw_21 = ((int)0);
		m_sw_22 = ((int)0);
		m_sw_23 = ((int)0);
		m_knob6_wetdry_24 = ((int)0);
		m_sw_25 = ((int)0);
		m_sw_26 = ((int)0);
		m_bws_27.reset("bws", ((int)32), ((int)1));
		m_knob2_amps_28 = ((int)0);
		m_sw_29 = ((int)0);
		m_knob4_voices_30 = ((int)4);
		m_knob_31 = ((int)0);
		m_amps_32.reset("amps", ((int)32), ((int)1));
		m_noise_33.reset("noise", ((int)48000), ((int)1));
		m_knob5_MIDIoffset_34 = ((int)0);
		m_knob_35 = ((int)0);
		m_sw_36 = ((int)0);
		m_fqs_37.reset("fqs", ((int)32), ((int)1));
		__m_change_38.reset(0);
		__m_change_39.reset(0);
		__m_change_40.reset(0);
		__m_change_41.reset(0);
		__m_change_42.reset(0);
		__m_count_43 = 0;
		__m_carry_45 = 0;
		__m_change_48.reset(0);
		__m_change_49.reset(0);
		__m_count_50 = 0;
		__m_carry_52 = 0;
		m_y_57 = ((int)0);
		m_history_58 = ((int)0);
		m_history_59 = ((int)0);
		m_history_60 = ((int)0);
		m_y_61 = ((int)0);
		__m_slide_62 = 0;
		__m_slide_65 = 0;
		__m_slide_68 = 0;
		__m_slide_71 = 0;
		m_y_76 = ((int)0);
		m_history_77 = ((int)0);
		m_history_78 = ((int)0);
		m_history_79 = ((int)0);
		m_y_80 = ((int)0);
		__m_slide_81 = 0;
		__m_slide_84 = 0;
		__m_slide_87 = 0;
		__m_slide_90 = 0;
		m_y_95 = ((int)0);
		m_history_96 = ((int)0);
		m_history_97 = ((int)0);
		m_history_98 = ((int)0);
		m_y_99 = ((int)0);
		__m_slide_100 = 0;
		__m_slide_103 = 0;
		__m_slide_106 = 0;
		__m_slide_109 = 0;
		m_y_114 = ((int)0);
		m_history_115 = ((int)0);
		m_history_116 = ((int)0);
		m_history_117 = ((int)0);
		m_y_118 = ((int)0);
		__m_slide_119 = 0;
		__m_slide_122 = 0;
		__m_slide_125 = 0;
		__m_slide_128 = 0;
		m_y_133 = ((int)0);
		m_history_134 = ((int)0);
		m_history_135 = ((int)0);
		m_history_136 = ((int)0);
		m_y_137 = ((int)0);
		__m_slide_138 = 0;
		__m_slide_141 = 0;
		__m_slide_144 = 0;
		__m_slide_147 = 0;
		m_y_152 = ((int)0);
		m_history_153 = ((int)0);
		m_history_154 = ((int)0);
		m_history_155 = ((int)0);
		m_y_156 = ((int)0);
		__m_slide_157 = 0;
		__m_slide_160 = 0;
		__m_slide_163 = 0;
		__m_slide_166 = 0;
		m_y_171 = ((int)0);
		m_history_172 = ((int)0);
		m_history_173 = ((int)0);
		m_history_174 = ((int)0);
		m_y_175 = ((int)0);
		__m_slide_176 = 0;
		__m_slide_179 = 0;
		__m_slide_182 = 0;
		__m_slide_185 = 0;
		m_y_190 = ((int)0);
		m_history_191 = ((int)0);
		m_history_192 = ((int)0);
		m_history_193 = ((int)0);
		m_y_194 = ((int)0);
		__m_slide_195 = 0;
		__m_slide_198 = 0;
		__m_slide_201 = 0;
		__m_slide_204 = 0;
		m_y_209 = ((int)0);
		m_history_210 = ((int)0);
		m_history_211 = ((int)0);
		m_history_212 = ((int)0);
		m_y_213 = ((int)0);
		__m_slide_214 = 0;
		__m_slide_217 = 0;
		__m_slide_220 = 0;
		__m_slide_223 = 0;
		m_y_228 = ((int)0);
		m_history_229 = ((int)0);
		m_history_230 = ((int)0);
		m_history_231 = ((int)0);
		m_y_232 = ((int)0);
		__m_slide_233 = 0;
		__m_slide_236 = 0;
		__m_slide_239 = 0;
		__m_slide_242 = 0;
		m_y_247 = ((int)0);
		m_history_248 = ((int)0);
		m_history_249 = ((int)0);
		m_history_250 = ((int)0);
		m_y_251 = ((int)0);
		__m_slide_252 = 0;
		__m_slide_255 = 0;
		__m_slide_258 = 0;
		__m_slide_261 = 0;
		m_y_266 = ((int)0);
		m_history_267 = ((int)0);
		m_history_268 = ((int)0);
		m_history_269 = ((int)0);
		m_y_270 = ((int)0);
		__m_slide_271 = 0;
		__m_slide_274 = 0;
		__m_slide_277 = 0;
		__m_slide_280 = 0;
		m_y_285 = ((int)0);
		m_history_286 = ((int)0);
		m_history_287 = ((int)0);
		m_history_288 = ((int)0);
		m_y_289 = ((int)0);
		__m_slide_290 = 0;
		__m_slide_293 = 0;
		__m_slide_296 = 0;
		__m_slide_299 = 0;
		m_y_304 = ((int)0);
		m_history_305 = ((int)0);
		m_history_306 = ((int)0);
		m_history_307 = ((int)0);
		m_y_308 = ((int)0);
		__m_slide_309 = 0;
		__m_slide_312 = 0;
		__m_slide_315 = 0;
		__m_slide_318 = 0;
		m_y_323 = ((int)0);
		m_history_324 = ((int)0);
		m_history_325 = ((int)0);
		m_history_326 = ((int)0);
		m_y_327 = ((int)0);
		__m_slide_328 = 0;
		__m_slide_331 = 0;
		__m_slide_334 = 0;
		__m_slide_337 = 0;
		m_y_342 = ((int)0);
		m_history_343 = ((int)0);
		m_history_344 = ((int)0);
		m_history_345 = ((int)0);
		m_y_346 = ((int)0);
		__m_slide_347 = 0;
		__m_slide_350 = 0;
		__m_slide_353 = 0;
		__m_slide_356 = 0;
		m_y_361 = ((int)0);
		m_history_362 = ((int)0);
		m_history_363 = ((int)0);
		m_history_364 = ((int)0);
		m_y_365 = ((int)0);
		__m_slide_366 = 0;
		__m_slide_369 = 0;
		__m_slide_372 = 0;
		__m_slide_375 = 0;
		m_y_380 = ((int)0);
		m_history_381 = ((int)0);
		m_history_382 = ((int)0);
		m_history_383 = ((int)0);
		m_y_384 = ((int)0);
		__m_slide_385 = 0;
		__m_slide_388 = 0;
		__m_slide_391 = 0;
		__m_slide_394 = 0;
		m_y_399 = ((int)0);
		m_history_400 = ((int)0);
		m_history_401 = ((int)0);
		m_history_402 = ((int)0);
		m_y_403 = ((int)0);
		__m_slide_404 = 0;
		__m_slide_407 = 0;
		__m_slide_410 = 0;
		__m_slide_413 = 0;
		m_y_418 = ((int)0);
		m_history_419 = ((int)0);
		m_history_420 = ((int)0);
		m_history_421 = ((int)0);
		m_y_422 = ((int)0);
		__m_slide_423 = 0;
		__m_slide_426 = 0;
		__m_slide_429 = 0;
		__m_slide_432 = 0;
		m_y_437 = ((int)0);
		m_history_438 = ((int)0);
		m_history_439 = ((int)0);
		m_history_440 = ((int)0);
		m_y_441 = ((int)0);
		__m_slide_442 = 0;
		__m_slide_445 = 0;
		__m_slide_448 = 0;
		__m_slide_451 = 0;
		m_y_456 = ((int)0);
		m_history_457 = ((int)0);
		m_history_458 = ((int)0);
		m_history_459 = ((int)0);
		m_y_460 = ((int)0);
		__m_slide_461 = 0;
		__m_slide_464 = 0;
		__m_slide_467 = 0;
		__m_slide_470 = 0;
		m_y_475 = ((int)0);
		m_history_476 = ((int)0);
		m_history_477 = ((int)0);
		m_history_478 = ((int)0);
		m_y_479 = ((int)0);
		__m_slide_480 = 0;
		__m_slide_483 = 0;
		__m_slide_486 = 0;
		__m_slide_489 = 0;
		m_y_494 = ((int)0);
		m_history_495 = ((int)0);
		m_history_496 = ((int)0);
		m_history_497 = ((int)0);
		m_y_498 = ((int)0);
		__m_slide_499 = 0;
		__m_slide_502 = 0;
		__m_slide_505 = 0;
		__m_slide_508 = 0;
		m_y_513 = ((int)0);
		m_history_514 = ((int)0);
		m_history_515 = ((int)0);
		m_history_516 = ((int)0);
		m_y_517 = ((int)0);
		__m_slide_518 = 0;
		__m_slide_521 = 0;
		__m_slide_524 = 0;
		__m_slide_527 = 0;
		m_y_532 = ((int)0);
		m_history_533 = ((int)0);
		m_history_534 = ((int)0);
		m_history_535 = ((int)0);
		m_y_536 = ((int)0);
		__m_slide_537 = 0;
		__m_slide_540 = 0;
		__m_slide_543 = 0;
		__m_slide_546 = 0;
		m_y_551 = ((int)0);
		m_history_552 = ((int)0);
		m_history_553 = ((int)0);
		m_history_554 = ((int)0);
		m_y_555 = ((int)0);
		__m_slide_556 = 0;
		__m_slide_559 = 0;
		__m_slide_562 = 0;
		__m_slide_565 = 0;
		m_y_570 = ((int)0);
		m_history_571 = ((int)0);
		m_history_572 = ((int)0);
		m_history_573 = ((int)0);
		m_y_574 = ((int)0);
		__m_slide_575 = 0;
		__m_slide_578 = 0;
		__m_slide_581 = 0;
		__m_slide_584 = 0;
		m_y_589 = ((int)0);
		m_history_590 = ((int)0);
		m_history_591 = ((int)0);
		m_history_592 = ((int)0);
		m_y_593 = ((int)0);
		__m_slide_594 = 0;
		__m_slide_597 = 0;
		__m_slide_600 = 0;
		__m_slide_603 = 0;
		m_y_608 = ((int)0);
		m_history_609 = ((int)0);
		m_history_610 = ((int)0);
		m_history_611 = ((int)0);
		m_y_612 = ((int)0);
		__m_slide_613 = 0;
		__m_slide_616 = 0;
		__m_slide_619 = 0;
		__m_slide_622 = 0;
		m_y_627 = ((int)0);
		m_history_628 = ((int)0);
		m_history_629 = ((int)0);
		m_history_630 = ((int)0);
		m_y_631 = ((int)0);
		__m_slide_632 = 0;
		__m_slide_635 = 0;
		__m_slide_638 = 0;
		__m_slide_641 = 0;
		m_y_646 = ((int)0);
		m_history_647 = ((int)0);
		m_history_648 = ((int)0);
		m_history_649 = ((int)0);
		m_y_650 = ((int)0);
		__m_slide_651 = 0;
		__m_slide_654 = 0;
		__m_slide_657 = 0;
		__m_slide_660 = 0;
		__m_change_664.reset(0);
		elapsed = 0;
		__m_change_665.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_667.reset(0);
		__m_change_668.reset(0);
		__m_latch_669 = 0;
		__m_latch_670 = 0;
		__m_latch_671 = 0;
		__m_latch_672 = 0;
		__m_latch_673 = 0;
		__m_latch_674 = 0;
		__m_pluseq_675.reset(0);
		__m_count_677 = 0;
		__m_carry_679 = 0;
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		t_sample * __out3 = __outs[2];
		t_sample * __out4 = __outs[3];
		t_sample * __out5 = __outs[4];
		t_sample * __out6 = __outs[5];
		t_sample * __out7 = __outs[6];
		t_sample * __out8 = __outs[7];
		t_sample * __out9 = __outs[8];
		t_sample * __out10 = __outs[9];
		t_sample * __out11 = __outs[10];
		t_sample * __out12 = __outs[11];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) || (__out7 == 0) || (__out8 == 0) || (__out9 == 0) || (__out10 == 0) || (__out11 == 0) || (__out12 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		int int_10970 = int(m_sw_36);
		int int_25387 = int(m_sw_25);
		int int_25389 = int(m_sw_22);
		int int_25392 = int(m_sw_20);
		int int_25396 = int(m_sw_26);
		int amps_dim = m_amps_32.dim;
		int amps_channels = m_amps_32.channels;
		int int_25398 = int(m_sw_23);
		int int_25401 = int(m_sw_29);
		int fqs_dim = m_fqs_37.dim;
		int fqs_channels = m_fqs_37.channels;
		int bws_dim = m_bws_27.dim;
		int bws_channels = m_bws_27.channels;
		int int_25404 = int(m_sw_21);
		t_sample floor_20411 = floor(m_knob5_MIDIoffset_34);
		__loopcount = (__n * GENLIB_LOOPCOUNT_BAIL);
		samples_to_seconds = (1 / samplerate);
		int noise_dim = m_noise_33.dim;
		int noise_channels = m_noise_33.channels;
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out11 = ((int)0);
			t_sample out12 = ((int)0);
			int change_10971 = __m_change_38(int_10970);
			int eqp_10972 = ((int_10970 == change_10971) ? int_10970 : 0);
			t_sample out6 = eqp_10972;
			int change_25388 = __m_change_39(int_25387);
			int eqp_25386 = ((int_25387 == change_25388) ? int_25387 : 0);
			t_sample out10 = eqp_25386;
			int change_25390 = __m_change_40(int_25389);
			int eqp_25391 = ((int_25389 == change_25390) ? int_25389 : 0);
			t_sample out5 = eqp_25391;
			int change_25393 = __m_change_41(int_25392);
			int eqp_25394 = ((int_25392 == change_25393) ? int_25392 : 0);
			t_sample out9 = eqp_25394;
			int change_25397 = __m_change_42(int_25396);
			int eqp_25395 = ((int_25396 == change_25397) ? int_25396 : 0);
			t_sample out7 = eqp_25395;
			__m_count_43 = (((int)0) ? 0 : (fixdenorm(__m_count_43 + ((int)1))));
			int carry_44 = 0;
			if ((((int)0) != 0)) {
				__m_count_43 = 0;
				__m_carry_45 = 0;
				
			} else if (((((int)32) > 0) && (__m_count_43 >= ((int)32)))) {
				int wraps_46 = (__m_count_43 / ((int)32));
				__m_carry_45 = (__m_carry_45 + wraps_46);
				__m_count_43 = (__m_count_43 - (wraps_46 * ((int)32)));
				carry_44 = 1;
				
			};
			int counter_24426 = __m_count_43;
			int counter_24427 = carry_44;
			int counter_24428 = __m_carry_45;
			bool index_ignore_47 = ((counter_24426 >= amps_dim) || (counter_24426 < 0));
			if ((!index_ignore_47)) {
				m_amps_32.write(m_knob2_amps_28, counter_24426, 0);
				
			};
			int change_25399 = __m_change_48(int_25398);
			int eqp_25400 = ((int_25398 == change_25399) ? int_25398 : 0);
			t_sample out4 = eqp_25400;
			int change_25402 = __m_change_49(int_25401);
			int eqp_25403 = ((int_25401 == change_25402) ? int_25401 : 0);
			t_sample out3 = eqp_25403;
			__m_count_50 = (((int)0) ? 0 : (fixdenorm(__m_count_50 + ((int)1))));
			int carry_51 = 0;
			if ((((int)0) != 0)) {
				__m_count_50 = 0;
				__m_carry_52 = 0;
				
			} else if (((m_knob4_voices_30 > 0) && (__m_count_50 >= m_knob4_voices_30))) {
				int wraps_53 = (__m_count_50 / m_knob4_voices_30);
				__m_carry_52 = (__m_carry_52 + wraps_53);
				__m_count_50 = (__m_count_50 - (wraps_53 * m_knob4_voices_30));
				carry_51 = 1;
				
			};
			int i = __m_count_50;
			bool index_ignore_54 = ((i >= fqs_dim) || (i < 0));
			// samples fqs channel 1;
			t_sample freq = (index_ignore_54 ? 0 : m_fqs_37.read(i, 0));
			bool index_ignore_55 = ((i >= amps_dim) || (i < 0));
			// samples amps channel 1;
			t_sample a = (index_ignore_55 ? 0 : m_amps_32.read(i, 0));
			bool index_ignore_56 = ((i >= bws_dim) || (i < 0));
			// samples bws channel 1;
			t_sample bw = (index_ignore_56 ? 0 : m_bws_27.read(i, 0));
			t_sample f = safediv((freq * ((t_sample)6.2831853071796)), samplerate);
			t_sample sub_25762 = (bw - ((int)0));
			t_sample scale_25759 = ((safepow((sub_25762 * ((t_sample)1)), ((int)2)) * ((t_sample)9.5)) + ((t_sample)0.5));
			t_sample b = safediv((scale_25759 * ((t_sample)6.2831853071796)), samplerate);
			t_sample expr_25767 = (((int)0) + earth_resonator_d_i_d_d_d_i_i((in2 + in1), i, f, a, b, ((int)0), ((int)0)));
			t_sample expr_25768 = (expr_25767 + earth_resonator_d_i_d_d_d_i_i_75((in2 + in1), i, f, a, b, ((int)1), ((int)0)));
			t_sample expr_25769 = (expr_25768 + earth_resonator_d_i_d_d_d_i_i_94((in2 + in1), i, f, a, b, ((int)2), ((int)0)));
			t_sample expr_25770 = (expr_25769 + earth_resonator_d_i_d_d_d_i_i_113((in2 + in1), i, f, a, b, ((int)3), ((int)0)));
			t_sample expr_25771 = (expr_25770 + earth_resonator_d_i_d_d_d_i_i_132((in2 + in1), i, f, a, b, ((int)4), ((int)0)));
			t_sample expr_25772 = (expr_25771 + earth_resonator_d_i_d_d_d_i_i_151((in2 + in1), i, f, a, b, ((int)5), ((int)0)));
			t_sample expr_25773 = (expr_25772 + earth_resonator_d_i_d_d_d_i_i_170((in2 + in1), i, f, a, b, ((int)6), ((int)0)));
			t_sample expr_25774 = (expr_25773 + earth_resonator_d_i_d_d_d_i_i_189((in2 + in1), i, f, a, b, ((int)7), ((int)0)));
			t_sample expr_25775 = (expr_25774 + earth_resonator_d_i_d_d_d_i_i_208((in2 + in1), i, f, a, b, ((int)8), ((int)0)));
			t_sample expr_25776 = (expr_25775 + earth_resonator_d_i_d_d_d_i_i_227((in2 + in1), i, f, a, b, ((int)9), ((int)0)));
			t_sample expr_25777 = (expr_25776 + earth_resonator_d_i_d_d_d_i_i_246((in2 + in1), i, f, a, b, ((int)10), ((int)0)));
			t_sample expr_25778 = (expr_25777 + earth_resonator_d_i_d_d_d_i_i_265((in2 + in1), i, f, a, b, ((int)11), ((int)0)));
			t_sample expr_25779 = (expr_25778 + earth_resonator_d_i_d_d_d_i_i_284((in2 + in1), i, f, a, b, ((int)12), ((int)0)));
			t_sample expr_25780 = (expr_25779 + earth_resonator_d_i_d_d_d_i_i_303((in2 + in1), i, f, a, b, ((int)13), ((int)0)));
			t_sample expr_25781 = (expr_25780 + earth_resonator_d_i_d_d_d_i_i_322((in2 + in1), i, f, a, b, ((int)14), ((int)0)));
			t_sample expr_25782 = (expr_25781 + earth_resonator_d_i_d_d_d_i_i_341((in2 + in1), i, f, a, b, ((int)15), ((int)0)));
			t_sample expr_25783 = (expr_25782 + earth_resonator_d_i_d_d_d_i_i_360((in2 + in1), i, f, a, b, ((int)16), ((int)0)));
			t_sample expr_25784 = (expr_25783 + earth_resonator_d_i_d_d_d_i_i_379((in2 + in1), i, f, a, b, ((int)17), ((int)0)));
			t_sample expr_25785 = (expr_25784 + earth_resonator_d_i_d_d_d_i_i_398((in2 + in1), i, f, a, b, ((int)18), ((int)0)));
			t_sample expr_25786 = (expr_25785 + earth_resonator_d_i_d_d_d_i_i_417((in2 + in1), i, f, a, b, ((int)19), ((int)0)));
			t_sample expr_25787 = (expr_25786 + earth_resonator_d_i_d_d_d_i_i_436((in2 + in1), i, f, a, b, ((int)20), ((int)0)));
			t_sample expr_25788 = (expr_25787 + earth_resonator_d_i_d_d_d_i_i_455((in2 + in1), i, f, a, b, ((int)21), ((int)0)));
			t_sample expr_25789 = (expr_25788 + earth_resonator_d_i_d_d_d_i_i_474((in2 + in1), i, f, a, b, ((int)22), ((int)0)));
			t_sample expr_25790 = (expr_25789 + earth_resonator_d_i_d_d_d_i_i_493((in2 + in1), i, f, a, b, ((int)23), ((int)0)));
			t_sample expr_25791 = (expr_25790 + earth_resonator_d_i_d_d_d_i_i_512((in2 + in1), i, f, a, b, ((int)24), ((int)0)));
			t_sample expr_25792 = (expr_25791 + earth_resonator_d_i_d_d_d_i_i_531((in2 + in1), i, f, a, b, ((int)25), ((int)0)));
			t_sample expr_25793 = (expr_25792 + earth_resonator_d_i_d_d_d_i_i_550((in2 + in1), i, f, a, b, ((int)26), ((int)0)));
			t_sample expr_25794 = (expr_25793 + earth_resonator_d_i_d_d_d_i_i_569((in2 + in1), i, f, a, b, ((int)27), ((int)0)));
			t_sample expr_25795 = (expr_25794 + earth_resonator_d_i_d_d_d_i_i_588((in2 + in1), i, f, a, b, ((int)28), ((int)0)));
			t_sample expr_25796 = (expr_25795 + earth_resonator_d_i_d_d_d_i_i_607((in2 + in1), i, f, a, b, ((int)29), ((int)0)));
			t_sample expr_25797 = (expr_25796 + earth_resonator_d_i_d_d_d_i_i_626((in2 + in1), i, f, a, b, ((int)30), ((int)0)));
			t_sample expr_25798 = (expr_25797 + earth_resonator_d_i_d_d_d_i_i_645((in2 + in1), i, f, a, b, ((int)31), ((int)0)));
			int change_25405 = __m_change_664(int_25404);
			int eqp_25406 = ((int_25404 == change_25405) ? int_25404 : 0);
			t_sample out8 = eqp_25406;
			if (((elapsed == ((int)0)) || __m_change_665((floor_20411 != ((int)1))))) {
				// for loop initializer;
				int index = ((int)0);
				// for loop condition;
				while ((index < ((int)32))) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					t_sample midi = ((go_quantize_d_i_i_i_i_i((index * ((t_sample)0.0625)), ((int)7), ((int)12), ((int)2), ((int)0), ((int)0)) * ((int)12)) + floor_20411);
					t_sample f_25407 = mtof(midi, ((int)440));
					bool index_ignore_666 = ((index >= fqs_dim) || (index < 0));
					if ((!index_ignore_666)) {
						m_fqs_37.write(f_25407, index, 0);
						
					};
					// for loop increment;
					index = (index + ((int)1));
					
				};
				
			};
			// abort processing if an infinite loop is suspected;
			if (((__loopcount--) <= 0)) {
				__exception = GENLIB_ERR_LOOP_OVERFLOW;
				break ;
				
			};
			t_sample noise_10786 = noise();
			t_sample phasor_10782 = __m_phasor_667(m_knob_35, samples_to_seconds);
			t_sample sub_10803 = (phasor_10782 - m_history_17);
			t_sample add_10804 = (phasor_10782 + m_history_17);
			t_sample div_10802 = safediv(sub_10803, add_10804);
			t_sample abs_10801 = fabs(div_10802);
			int gt_10799 = (abs_10801 > ((t_sample)0.5));
			int change_10798 = __m_change_668(gt_10799);
			int gt_10797 = (change_10798 > ((int)0));
			int gen_10806 = gt_10797;
			t_sample history_10800_next_10805 = fixdenorm(phasor_10782);
			__m_latch_669 = ((gen_10806 != 0) ? m_history_14 : __m_latch_669);
			t_sample latch_10794 = __m_latch_669;
			__m_latch_670 = ((gen_10806 != 0) ? noise_10786 : __m_latch_670);
			t_sample latch_10808 = __m_latch_670;
			__m_latch_671 = ((gen_10806 != 0) ? m_history_15 : __m_latch_671);
			t_sample latch_10796 = __m_latch_671;
			__m_latch_672 = ((gen_10806 != 0) ? m_history_16 : __m_latch_672);
			t_sample latch_10792 = __m_latch_672;
			__m_latch_673 = ((gen_10806 != 0) ? m_history_13 : __m_latch_673);
			t_sample latch_10789 = __m_latch_673;
			__m_latch_674 = ((gen_10806 != 0) ? m_history_12 : __m_latch_674);
			t_sample latch_10787 = __m_latch_674;
			t_sample spline_10791 = spline6_interp(phasor_10782, latch_10787, latch_10789, latch_10792, latch_10794, latch_10796, latch_10808);
			t_sample history_10793_next_10809 = fixdenorm(latch_10794);
			t_sample history_10807_next_10810 = fixdenorm(latch_10808);
			t_sample history_10795_next_10811 = fixdenorm(latch_10796);
			t_sample history_10790_next_10812 = fixdenorm(latch_10792);
			t_sample history_10788_next_10813 = fixdenorm(latch_10789);
			int plusequals_10783 = __m_pluseq_675.post(((int)1), ((int)0), 0);
			bool index_ignore_676 = ((plusequals_10783 >= noise_dim) || (plusequals_10783 < 0));
			if ((!index_ignore_676)) {
				m_noise_33.write(spline_10791, plusequals_10783, 0);
				
			};
			int switch_10773 = (m_history_1 ? ((int)0) : ((int)1));
			__m_count_677 = (((int)0) ? 0 : (fixdenorm(__m_count_677 + switch_10773)));
			int carry_678 = 0;
			if ((((int)0) != 0)) {
				__m_count_677 = 0;
				__m_carry_679 = 0;
				
			} else if (((((int)16) > 0) && (__m_count_677 >= ((int)16)))) {
				int wraps_680 = (__m_count_677 / ((int)16));
				__m_carry_679 = (__m_carry_679 + wraps_680);
				__m_count_677 = (__m_count_677 - (wraps_680 * ((int)16)));
				carry_678 = 1;
				
			};
			int counter_10776 = __m_count_677;
			int counter_10777 = carry_678;
			int counter_10778 = __m_carry_679;
			t_sample mul_10817 = (expr_25798 * ((t_sample)0.4));
			t_sample tap_10851 = m_delay_11.read_step(((int)8269));
			t_sample tap_10824 = m_delay_10.read_step(((int)3571));
			t_sample tap_10869 = m_delay_9.read_step(((int)4447));
			t_sample mul_10849 = (tap_10851 * ((t_sample)0.5));
			t_sample tap_10842 = m_delay_8.read_step(((int)2791));
			t_sample mul_10822 = (tap_10824 * ((t_sample)0.5));
			t_sample mix_25763 = (mul_10817 + (((t_sample)0.8) * (m_history_3 - mul_10817)));
			t_sample mix_10871 = mix_25763;
			t_sample add_10848 = (mix_10871 + mul_10849);
			t_sample mul_10847 = (add_10848 * ((t_sample)0.5));
			t_sample sub_10846 = (tap_10851 - mul_10847);
			t_sample gen_10874 = sub_10846;
			t_sample mix_25764 = (mul_10817 + (((t_sample)0.8) * (m_history_2 - mul_10817)));
			t_sample mix_10844 = mix_25764;
			t_sample add_10821 = (mix_10844 + mul_10822);
			t_sample mul_10820 = (add_10821 * ((t_sample)0.5));
			t_sample sub_10819 = (tap_10824 - mul_10820);
			t_sample gen_10875 = sub_10819;
			t_sample tap_10863 = m_delay_7.read_step(((int)7351));
			t_sample mul_10867 = (tap_10869 * ((t_sample)0.5));
			t_sample add_10866 = (add_10848 + mul_10867);
			t_sample mul_10865 = (add_10866 * ((t_sample)0.5));
			t_sample sub_10864 = (tap_10869 - mul_10865);
			t_sample tap_10836 = m_delay_6.read_step(((int)5167));
			t_sample mul_10840 = (tap_10842 * ((t_sample)0.5));
			t_sample add_10839 = (add_10821 + mul_10840);
			t_sample mul_10838 = (add_10839 * ((t_sample)0.5));
			t_sample sub_10837 = (tap_10842 - mul_10838);
			t_sample tap_10857 = m_delay_5.read_step(((int)5419));
			t_sample mul_10861 = (tap_10863 * ((t_sample)0.5));
			t_sample add_10860 = (add_10866 + mul_10861);
			t_sample mul_10859 = (add_10860 * ((t_sample)0.5));
			t_sample sub_10858 = (tap_10863 - mul_10859);
			t_sample tap_10830 = m_delay_4.read_step(((int)3469));
			t_sample mul_10834 = (tap_10836 * ((t_sample)0.5));
			t_sample add_10833 = (add_10839 + mul_10834);
			t_sample mul_10832 = (add_10833 * ((t_sample)0.5));
			t_sample sub_10831 = (tap_10836 - mul_10832);
			t_sample mul_10855 = (tap_10857 * ((t_sample)0.5));
			t_sample add_10854 = (add_10860 + mul_10855);
			t_sample mul_10853 = (add_10854 * ((t_sample)0.5));
			t_sample sub_10852 = (tap_10857 - mul_10853);
			t_sample mul_10828 = (tap_10830 * ((t_sample)0.5));
			t_sample add_10827 = (add_10833 + mul_10828);
			t_sample mul_10826 = (add_10827 * ((t_sample)0.5));
			t_sample sub_10825 = (tap_10830 - mul_10826);
			t_sample history_10870_next_10872 = fixdenorm(sub_10846);
			t_sample history_10843_next_10873 = fixdenorm(sub_10819);
			t_sample mix_25765 = (gen_10874 + (m_knob6_wetdry_24 * (in1 - gen_10874)));
			t_sample out1 = mix_25765;
			t_sample mix_25766 = (gen_10875 + (m_knob6_wetdry_24 * (in2 - gen_10875)));
			t_sample out2 = mix_25766;
			t_sample div_10771 = (counter_10776 * ((t_sample)0.0625));
			t_sample div_10770 = (div_10771 * ((t_sample)0.1));
			double sample_index_681 = (div_10770 * (noise_dim - 1));
			int index_trunc_682 = fixnan(floor(sample_index_681));
			double index_fract_683 = (sample_index_681 - index_trunc_682);
			int index_trunc_684 = (index_trunc_682 + 1);
			bool index_ignore_685 = ((index_trunc_682 >= noise_dim) || (index_trunc_682 < 0));
			bool index_ignore_686 = ((index_trunc_684 >= noise_dim) || (index_trunc_684 < 0));
			// phase noise channel 1;
			double read_noise_687 = (index_ignore_685 ? 0 : m_noise_33.read(index_trunc_682, 0));
			double read_noise_688 = (index_ignore_686 ? 0 : m_noise_33.read(index_trunc_684, 0));
			double readinterp_689 = linear_interp(index_fract_683, read_noise_687, read_noise_688);
			t_sample sample_noise_10779 = readinterp_689;
			t_sample index_noise_10780 = sample_index_681;
			bool index_ignore_690 = ((counter_10776 >= bws_dim) || (counter_10776 < 0));
			if ((!index_ignore_690)) {
				m_bws_27.write(sample_noise_10779, counter_10776, 0);
				
			};
			t_sample history_10772_next_25408 = fixdenorm(counter_10777);
			m_history_17 = history_10800_next_10805;
			m_history_12 = history_10788_next_10813;
			m_history_13 = history_10790_next_10812;
			m_history_14 = history_10795_next_10811;
			m_history_15 = history_10807_next_10810;
			m_history_16 = history_10793_next_10809;
			m_delay_11.write(sub_10864);
			m_history_2 = history_10843_next_10873;
			m_history_3 = history_10870_next_10872;
			m_delay_4.write(add_10827);
			m_delay_5.write(add_10854);
			m_delay_6.write(sub_10825);
			m_delay_7.write(sub_10852);
			m_delay_8.write(sub_10831);
			m_delay_9.write(sub_10858);
			m_delay_10.write(sub_10837);
			m_history_1 = history_10772_next_25408;
			m_delay_4.step();
			m_delay_5.step();
			m_delay_6.step();
			m_delay_7.step();
			m_delay_8.step();
			m_delay_9.step();
			m_delay_10.step();
			m_delay_11.step();
			(elapsed++);
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			(*(__out3++)) = out3;
			(*(__out4++)) = out4;
			(*(__out5++)) = out5;
			(*(__out6++)) = out6;
			(*(__out7++)) = out7;
			(*(__out8++)) = out8;
			(*(__out9++)) = out9;
			(*(__out10++)) = out10;
			(*(__out11++)) = out11;
			(*(__out12++)) = out12;
			
		};
		return __exception;
		
	};
	inline void set_cvin1(t_param _value) {
		m_cvin_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate1(t_param _value) {
		m_gate_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw7(t_param _value) {
		m_sw_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw6(t_param _value) {
		m_sw_21 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw3(t_param _value) {
		m_sw_22 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_wetdry(t_param _value) {
		m_knob6_wetdry_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw8(t_param _value) {
		m_sw_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_bws(void * _value) {
		m_bws_27.setbuffer(_value);
	};
	inline void set_knob2_amps(t_param _value) {
		m_knob2_amps_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_voices(t_param _value) {
		m_knob4_voices_30 = (_value < 1 ? 1 : (_value > 33 ? 33 : _value));
	};
	inline void set_knob1(t_param _value) {
		m_knob_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_amps(void * _value) {
		m_amps_32.setbuffer(_value);
	};
	inline void set_noise(void * _value) {
		m_noise_33.setbuffer(_value);
	};
	inline void set_knob5_MIDIoffset(t_param _value) {
		m_knob5_MIDIoffset_34 = (_value < 32 ? 32 : (_value > 103 ? 103 : _value));
	};
	inline void set_knob3(t_param _value) {
		m_knob_35 = (_value < 0 ? 0 : (_value > 20 ? 20 : _value));
	};
	inline void set_sw4(t_param _value) {
		m_sw_36 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_fqs(void * _value) {
		m_fqs_37.setbuffer(_value);
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_63 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_64 = (1 / maximum(1, abs(((int)200))));
		__m_slide_62 = fixdenorm((__m_slide_62 + (((m_history_58 > __m_slide_62) ? iup_63 : idown_64) * (m_history_58 - __m_slide_62))));
		t_sample slide_25355 = __m_slide_62;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_58);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_59);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_60);
		int lt_25350 = (id < arg_25383);
		t_sample iup_66 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_67 = (1 / maximum(1, abs(((int)200))));
		__m_slide_65 = fixdenorm((__m_slide_65 + (((lt_25350 > __m_slide_65) ? iup_66 : idown_67) * (lt_25350 - __m_slide_65))));
		t_sample slide_25344 = __m_slide_65;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_69 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_70 = (1 / maximum(1, abs(((int)200))));
		__m_slide_68 = fixdenorm((__m_slide_68 + (((m_history_60 > __m_slide_68) ? iup_69 : idown_70) * (m_history_60 - __m_slide_68))));
		t_sample slide_25356 = __m_slide_68;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_72 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_73 = (1 / maximum(1, abs(((int)200))));
		__m_slide_71 = fixdenorm((__m_slide_71 + (((m_history_59 > __m_slide_71) ? iup_72 : idown_73) * (m_history_59 - __m_slide_71))));
		t_sample slide_25345 = __m_slide_71;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_61 * min_25353);
		t_sample mina_74 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_74) ? ((int)1) : mina_74);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_57 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_61);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_57 = y2_next_25373;
		m_y_61 = y1_next_25377;
		m_history_60 = history_25372_next_25376;
		m_history_59 = history_25346_next_25375;
		m_history_58 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_75(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_82 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_83 = (1 / maximum(1, abs(((int)200))));
		__m_slide_81 = fixdenorm((__m_slide_81 + (((m_history_77 > __m_slide_81) ? iup_82 : idown_83) * (m_history_77 - __m_slide_81))));
		t_sample slide_25355 = __m_slide_81;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_77);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_78);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_79);
		int lt_25350 = (id < arg_25383);
		t_sample iup_85 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_86 = (1 / maximum(1, abs(((int)200))));
		__m_slide_84 = fixdenorm((__m_slide_84 + (((lt_25350 > __m_slide_84) ? iup_85 : idown_86) * (lt_25350 - __m_slide_84))));
		t_sample slide_25344 = __m_slide_84;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_88 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_89 = (1 / maximum(1, abs(((int)200))));
		__m_slide_87 = fixdenorm((__m_slide_87 + (((m_history_79 > __m_slide_87) ? iup_88 : idown_89) * (m_history_79 - __m_slide_87))));
		t_sample slide_25356 = __m_slide_87;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_91 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_92 = (1 / maximum(1, abs(((int)200))));
		__m_slide_90 = fixdenorm((__m_slide_90 + (((m_history_78 > __m_slide_90) ? iup_91 : idown_92) * (m_history_78 - __m_slide_90))));
		t_sample slide_25345 = __m_slide_90;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_80 * min_25353);
		t_sample mina_93 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_93) ? ((int)1) : mina_93);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_76 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_80);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_76 = y2_next_25373;
		m_y_80 = y1_next_25377;
		m_history_79 = history_25372_next_25376;
		m_history_78 = history_25346_next_25375;
		m_history_77 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_94(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_101 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_102 = (1 / maximum(1, abs(((int)200))));
		__m_slide_100 = fixdenorm((__m_slide_100 + (((m_history_96 > __m_slide_100) ? iup_101 : idown_102) * (m_history_96 - __m_slide_100))));
		t_sample slide_25355 = __m_slide_100;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_96);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_97);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_98);
		int lt_25350 = (id < arg_25383);
		t_sample iup_104 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_105 = (1 / maximum(1, abs(((int)200))));
		__m_slide_103 = fixdenorm((__m_slide_103 + (((lt_25350 > __m_slide_103) ? iup_104 : idown_105) * (lt_25350 - __m_slide_103))));
		t_sample slide_25344 = __m_slide_103;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_107 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_108 = (1 / maximum(1, abs(((int)200))));
		__m_slide_106 = fixdenorm((__m_slide_106 + (((m_history_98 > __m_slide_106) ? iup_107 : idown_108) * (m_history_98 - __m_slide_106))));
		t_sample slide_25356 = __m_slide_106;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_110 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_111 = (1 / maximum(1, abs(((int)200))));
		__m_slide_109 = fixdenorm((__m_slide_109 + (((m_history_97 > __m_slide_109) ? iup_110 : idown_111) * (m_history_97 - __m_slide_109))));
		t_sample slide_25345 = __m_slide_109;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_99 * min_25353);
		t_sample mina_112 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_112) ? ((int)1) : mina_112);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_95 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_99);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_95 = y2_next_25373;
		m_y_99 = y1_next_25377;
		m_history_98 = history_25372_next_25376;
		m_history_97 = history_25346_next_25375;
		m_history_96 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_113(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_120 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_121 = (1 / maximum(1, abs(((int)200))));
		__m_slide_119 = fixdenorm((__m_slide_119 + (((m_history_115 > __m_slide_119) ? iup_120 : idown_121) * (m_history_115 - __m_slide_119))));
		t_sample slide_25355 = __m_slide_119;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_115);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_116);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_117);
		int lt_25350 = (id < arg_25383);
		t_sample iup_123 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_124 = (1 / maximum(1, abs(((int)200))));
		__m_slide_122 = fixdenorm((__m_slide_122 + (((lt_25350 > __m_slide_122) ? iup_123 : idown_124) * (lt_25350 - __m_slide_122))));
		t_sample slide_25344 = __m_slide_122;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_126 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_127 = (1 / maximum(1, abs(((int)200))));
		__m_slide_125 = fixdenorm((__m_slide_125 + (((m_history_117 > __m_slide_125) ? iup_126 : idown_127) * (m_history_117 - __m_slide_125))));
		t_sample slide_25356 = __m_slide_125;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_129 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_130 = (1 / maximum(1, abs(((int)200))));
		__m_slide_128 = fixdenorm((__m_slide_128 + (((m_history_116 > __m_slide_128) ? iup_129 : idown_130) * (m_history_116 - __m_slide_128))));
		t_sample slide_25345 = __m_slide_128;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_118 * min_25353);
		t_sample mina_131 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_131) ? ((int)1) : mina_131);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_114 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_118);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_114 = y2_next_25373;
		m_y_118 = y1_next_25377;
		m_history_117 = history_25372_next_25376;
		m_history_116 = history_25346_next_25375;
		m_history_115 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_132(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_139 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_140 = (1 / maximum(1, abs(((int)200))));
		__m_slide_138 = fixdenorm((__m_slide_138 + (((m_history_134 > __m_slide_138) ? iup_139 : idown_140) * (m_history_134 - __m_slide_138))));
		t_sample slide_25355 = __m_slide_138;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_134);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_135);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_136);
		int lt_25350 = (id < arg_25383);
		t_sample iup_142 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_143 = (1 / maximum(1, abs(((int)200))));
		__m_slide_141 = fixdenorm((__m_slide_141 + (((lt_25350 > __m_slide_141) ? iup_142 : idown_143) * (lt_25350 - __m_slide_141))));
		t_sample slide_25344 = __m_slide_141;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_145 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_146 = (1 / maximum(1, abs(((int)200))));
		__m_slide_144 = fixdenorm((__m_slide_144 + (((m_history_136 > __m_slide_144) ? iup_145 : idown_146) * (m_history_136 - __m_slide_144))));
		t_sample slide_25356 = __m_slide_144;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_148 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_149 = (1 / maximum(1, abs(((int)200))));
		__m_slide_147 = fixdenorm((__m_slide_147 + (((m_history_135 > __m_slide_147) ? iup_148 : idown_149) * (m_history_135 - __m_slide_147))));
		t_sample slide_25345 = __m_slide_147;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_137 * min_25353);
		t_sample mina_150 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_150) ? ((int)1) : mina_150);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_133 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_137);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_133 = y2_next_25373;
		m_y_137 = y1_next_25377;
		m_history_136 = history_25372_next_25376;
		m_history_135 = history_25346_next_25375;
		m_history_134 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_151(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_158 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_159 = (1 / maximum(1, abs(((int)200))));
		__m_slide_157 = fixdenorm((__m_slide_157 + (((m_history_153 > __m_slide_157) ? iup_158 : idown_159) * (m_history_153 - __m_slide_157))));
		t_sample slide_25355 = __m_slide_157;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_153);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_154);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_155);
		int lt_25350 = (id < arg_25383);
		t_sample iup_161 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_162 = (1 / maximum(1, abs(((int)200))));
		__m_slide_160 = fixdenorm((__m_slide_160 + (((lt_25350 > __m_slide_160) ? iup_161 : idown_162) * (lt_25350 - __m_slide_160))));
		t_sample slide_25344 = __m_slide_160;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_164 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_165 = (1 / maximum(1, abs(((int)200))));
		__m_slide_163 = fixdenorm((__m_slide_163 + (((m_history_155 > __m_slide_163) ? iup_164 : idown_165) * (m_history_155 - __m_slide_163))));
		t_sample slide_25356 = __m_slide_163;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_167 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_168 = (1 / maximum(1, abs(((int)200))));
		__m_slide_166 = fixdenorm((__m_slide_166 + (((m_history_154 > __m_slide_166) ? iup_167 : idown_168) * (m_history_154 - __m_slide_166))));
		t_sample slide_25345 = __m_slide_166;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_156 * min_25353);
		t_sample mina_169 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_169) ? ((int)1) : mina_169);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_152 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_156);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_152 = y2_next_25373;
		m_y_156 = y1_next_25377;
		m_history_155 = history_25372_next_25376;
		m_history_154 = history_25346_next_25375;
		m_history_153 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_170(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_177 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_178 = (1 / maximum(1, abs(((int)200))));
		__m_slide_176 = fixdenorm((__m_slide_176 + (((m_history_172 > __m_slide_176) ? iup_177 : idown_178) * (m_history_172 - __m_slide_176))));
		t_sample slide_25355 = __m_slide_176;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_172);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_173);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_174);
		int lt_25350 = (id < arg_25383);
		t_sample iup_180 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_181 = (1 / maximum(1, abs(((int)200))));
		__m_slide_179 = fixdenorm((__m_slide_179 + (((lt_25350 > __m_slide_179) ? iup_180 : idown_181) * (lt_25350 - __m_slide_179))));
		t_sample slide_25344 = __m_slide_179;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_183 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_184 = (1 / maximum(1, abs(((int)200))));
		__m_slide_182 = fixdenorm((__m_slide_182 + (((m_history_174 > __m_slide_182) ? iup_183 : idown_184) * (m_history_174 - __m_slide_182))));
		t_sample slide_25356 = __m_slide_182;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_186 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_187 = (1 / maximum(1, abs(((int)200))));
		__m_slide_185 = fixdenorm((__m_slide_185 + (((m_history_173 > __m_slide_185) ? iup_186 : idown_187) * (m_history_173 - __m_slide_185))));
		t_sample slide_25345 = __m_slide_185;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_175 * min_25353);
		t_sample mina_188 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_188) ? ((int)1) : mina_188);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_171 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_175);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_171 = y2_next_25373;
		m_y_175 = y1_next_25377;
		m_history_174 = history_25372_next_25376;
		m_history_173 = history_25346_next_25375;
		m_history_172 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_189(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_196 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_197 = (1 / maximum(1, abs(((int)200))));
		__m_slide_195 = fixdenorm((__m_slide_195 + (((m_history_191 > __m_slide_195) ? iup_196 : idown_197) * (m_history_191 - __m_slide_195))));
		t_sample slide_25355 = __m_slide_195;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_191);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_192);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_193);
		int lt_25350 = (id < arg_25383);
		t_sample iup_199 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_200 = (1 / maximum(1, abs(((int)200))));
		__m_slide_198 = fixdenorm((__m_slide_198 + (((lt_25350 > __m_slide_198) ? iup_199 : idown_200) * (lt_25350 - __m_slide_198))));
		t_sample slide_25344 = __m_slide_198;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_202 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_203 = (1 / maximum(1, abs(((int)200))));
		__m_slide_201 = fixdenorm((__m_slide_201 + (((m_history_193 > __m_slide_201) ? iup_202 : idown_203) * (m_history_193 - __m_slide_201))));
		t_sample slide_25356 = __m_slide_201;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_205 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_206 = (1 / maximum(1, abs(((int)200))));
		__m_slide_204 = fixdenorm((__m_slide_204 + (((m_history_192 > __m_slide_204) ? iup_205 : idown_206) * (m_history_192 - __m_slide_204))));
		t_sample slide_25345 = __m_slide_204;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_194 * min_25353);
		t_sample mina_207 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_207) ? ((int)1) : mina_207);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_190 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_194);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_190 = y2_next_25373;
		m_y_194 = y1_next_25377;
		m_history_193 = history_25372_next_25376;
		m_history_192 = history_25346_next_25375;
		m_history_191 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_208(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_215 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_216 = (1 / maximum(1, abs(((int)200))));
		__m_slide_214 = fixdenorm((__m_slide_214 + (((m_history_210 > __m_slide_214) ? iup_215 : idown_216) * (m_history_210 - __m_slide_214))));
		t_sample slide_25355 = __m_slide_214;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_210);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_211);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_212);
		int lt_25350 = (id < arg_25383);
		t_sample iup_218 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_219 = (1 / maximum(1, abs(((int)200))));
		__m_slide_217 = fixdenorm((__m_slide_217 + (((lt_25350 > __m_slide_217) ? iup_218 : idown_219) * (lt_25350 - __m_slide_217))));
		t_sample slide_25344 = __m_slide_217;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_221 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_222 = (1 / maximum(1, abs(((int)200))));
		__m_slide_220 = fixdenorm((__m_slide_220 + (((m_history_212 > __m_slide_220) ? iup_221 : idown_222) * (m_history_212 - __m_slide_220))));
		t_sample slide_25356 = __m_slide_220;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_224 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_225 = (1 / maximum(1, abs(((int)200))));
		__m_slide_223 = fixdenorm((__m_slide_223 + (((m_history_211 > __m_slide_223) ? iup_224 : idown_225) * (m_history_211 - __m_slide_223))));
		t_sample slide_25345 = __m_slide_223;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_213 * min_25353);
		t_sample mina_226 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_226) ? ((int)1) : mina_226);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_209 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_213);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_209 = y2_next_25373;
		m_y_213 = y1_next_25377;
		m_history_212 = history_25372_next_25376;
		m_history_211 = history_25346_next_25375;
		m_history_210 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_227(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_234 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_235 = (1 / maximum(1, abs(((int)200))));
		__m_slide_233 = fixdenorm((__m_slide_233 + (((m_history_229 > __m_slide_233) ? iup_234 : idown_235) * (m_history_229 - __m_slide_233))));
		t_sample slide_25355 = __m_slide_233;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_229);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_230);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_231);
		int lt_25350 = (id < arg_25383);
		t_sample iup_237 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_238 = (1 / maximum(1, abs(((int)200))));
		__m_slide_236 = fixdenorm((__m_slide_236 + (((lt_25350 > __m_slide_236) ? iup_237 : idown_238) * (lt_25350 - __m_slide_236))));
		t_sample slide_25344 = __m_slide_236;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_240 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_241 = (1 / maximum(1, abs(((int)200))));
		__m_slide_239 = fixdenorm((__m_slide_239 + (((m_history_231 > __m_slide_239) ? iup_240 : idown_241) * (m_history_231 - __m_slide_239))));
		t_sample slide_25356 = __m_slide_239;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_243 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_244 = (1 / maximum(1, abs(((int)200))));
		__m_slide_242 = fixdenorm((__m_slide_242 + (((m_history_230 > __m_slide_242) ? iup_243 : idown_244) * (m_history_230 - __m_slide_242))));
		t_sample slide_25345 = __m_slide_242;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_232 * min_25353);
		t_sample mina_245 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_245) ? ((int)1) : mina_245);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_228 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_232);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_228 = y2_next_25373;
		m_y_232 = y1_next_25377;
		m_history_231 = history_25372_next_25376;
		m_history_230 = history_25346_next_25375;
		m_history_229 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_246(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_253 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_254 = (1 / maximum(1, abs(((int)200))));
		__m_slide_252 = fixdenorm((__m_slide_252 + (((m_history_248 > __m_slide_252) ? iup_253 : idown_254) * (m_history_248 - __m_slide_252))));
		t_sample slide_25355 = __m_slide_252;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_248);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_249);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_250);
		int lt_25350 = (id < arg_25383);
		t_sample iup_256 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_257 = (1 / maximum(1, abs(((int)200))));
		__m_slide_255 = fixdenorm((__m_slide_255 + (((lt_25350 > __m_slide_255) ? iup_256 : idown_257) * (lt_25350 - __m_slide_255))));
		t_sample slide_25344 = __m_slide_255;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_259 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_260 = (1 / maximum(1, abs(((int)200))));
		__m_slide_258 = fixdenorm((__m_slide_258 + (((m_history_250 > __m_slide_258) ? iup_259 : idown_260) * (m_history_250 - __m_slide_258))));
		t_sample slide_25356 = __m_slide_258;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_262 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_263 = (1 / maximum(1, abs(((int)200))));
		__m_slide_261 = fixdenorm((__m_slide_261 + (((m_history_249 > __m_slide_261) ? iup_262 : idown_263) * (m_history_249 - __m_slide_261))));
		t_sample slide_25345 = __m_slide_261;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_251 * min_25353);
		t_sample mina_264 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_264) ? ((int)1) : mina_264);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_247 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_251);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_247 = y2_next_25373;
		m_y_251 = y1_next_25377;
		m_history_250 = history_25372_next_25376;
		m_history_249 = history_25346_next_25375;
		m_history_248 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_265(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_272 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_273 = (1 / maximum(1, abs(((int)200))));
		__m_slide_271 = fixdenorm((__m_slide_271 + (((m_history_267 > __m_slide_271) ? iup_272 : idown_273) * (m_history_267 - __m_slide_271))));
		t_sample slide_25355 = __m_slide_271;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_267);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_268);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_269);
		int lt_25350 = (id < arg_25383);
		t_sample iup_275 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_276 = (1 / maximum(1, abs(((int)200))));
		__m_slide_274 = fixdenorm((__m_slide_274 + (((lt_25350 > __m_slide_274) ? iup_275 : idown_276) * (lt_25350 - __m_slide_274))));
		t_sample slide_25344 = __m_slide_274;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_278 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_279 = (1 / maximum(1, abs(((int)200))));
		__m_slide_277 = fixdenorm((__m_slide_277 + (((m_history_269 > __m_slide_277) ? iup_278 : idown_279) * (m_history_269 - __m_slide_277))));
		t_sample slide_25356 = __m_slide_277;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_281 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_282 = (1 / maximum(1, abs(((int)200))));
		__m_slide_280 = fixdenorm((__m_slide_280 + (((m_history_268 > __m_slide_280) ? iup_281 : idown_282) * (m_history_268 - __m_slide_280))));
		t_sample slide_25345 = __m_slide_280;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_270 * min_25353);
		t_sample mina_283 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_283) ? ((int)1) : mina_283);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_266 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_270);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_266 = y2_next_25373;
		m_y_270 = y1_next_25377;
		m_history_269 = history_25372_next_25376;
		m_history_268 = history_25346_next_25375;
		m_history_267 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_284(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_291 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_292 = (1 / maximum(1, abs(((int)200))));
		__m_slide_290 = fixdenorm((__m_slide_290 + (((m_history_286 > __m_slide_290) ? iup_291 : idown_292) * (m_history_286 - __m_slide_290))));
		t_sample slide_25355 = __m_slide_290;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_286);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_287);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_288);
		int lt_25350 = (id < arg_25383);
		t_sample iup_294 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_295 = (1 / maximum(1, abs(((int)200))));
		__m_slide_293 = fixdenorm((__m_slide_293 + (((lt_25350 > __m_slide_293) ? iup_294 : idown_295) * (lt_25350 - __m_slide_293))));
		t_sample slide_25344 = __m_slide_293;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_297 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_298 = (1 / maximum(1, abs(((int)200))));
		__m_slide_296 = fixdenorm((__m_slide_296 + (((m_history_288 > __m_slide_296) ? iup_297 : idown_298) * (m_history_288 - __m_slide_296))));
		t_sample slide_25356 = __m_slide_296;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_300 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_301 = (1 / maximum(1, abs(((int)200))));
		__m_slide_299 = fixdenorm((__m_slide_299 + (((m_history_287 > __m_slide_299) ? iup_300 : idown_301) * (m_history_287 - __m_slide_299))));
		t_sample slide_25345 = __m_slide_299;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_289 * min_25353);
		t_sample mina_302 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_302) ? ((int)1) : mina_302);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_285 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_289);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_285 = y2_next_25373;
		m_y_289 = y1_next_25377;
		m_history_288 = history_25372_next_25376;
		m_history_287 = history_25346_next_25375;
		m_history_286 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_303(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_310 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_311 = (1 / maximum(1, abs(((int)200))));
		__m_slide_309 = fixdenorm((__m_slide_309 + (((m_history_305 > __m_slide_309) ? iup_310 : idown_311) * (m_history_305 - __m_slide_309))));
		t_sample slide_25355 = __m_slide_309;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_305);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_306);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_307);
		int lt_25350 = (id < arg_25383);
		t_sample iup_313 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_314 = (1 / maximum(1, abs(((int)200))));
		__m_slide_312 = fixdenorm((__m_slide_312 + (((lt_25350 > __m_slide_312) ? iup_313 : idown_314) * (lt_25350 - __m_slide_312))));
		t_sample slide_25344 = __m_slide_312;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_316 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_317 = (1 / maximum(1, abs(((int)200))));
		__m_slide_315 = fixdenorm((__m_slide_315 + (((m_history_307 > __m_slide_315) ? iup_316 : idown_317) * (m_history_307 - __m_slide_315))));
		t_sample slide_25356 = __m_slide_315;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_319 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_320 = (1 / maximum(1, abs(((int)200))));
		__m_slide_318 = fixdenorm((__m_slide_318 + (((m_history_306 > __m_slide_318) ? iup_319 : idown_320) * (m_history_306 - __m_slide_318))));
		t_sample slide_25345 = __m_slide_318;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_308 * min_25353);
		t_sample mina_321 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_321) ? ((int)1) : mina_321);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_304 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_308);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_304 = y2_next_25373;
		m_y_308 = y1_next_25377;
		m_history_307 = history_25372_next_25376;
		m_history_306 = history_25346_next_25375;
		m_history_305 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_322(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_329 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_330 = (1 / maximum(1, abs(((int)200))));
		__m_slide_328 = fixdenorm((__m_slide_328 + (((m_history_324 > __m_slide_328) ? iup_329 : idown_330) * (m_history_324 - __m_slide_328))));
		t_sample slide_25355 = __m_slide_328;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_324);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_325);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_326);
		int lt_25350 = (id < arg_25383);
		t_sample iup_332 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_333 = (1 / maximum(1, abs(((int)200))));
		__m_slide_331 = fixdenorm((__m_slide_331 + (((lt_25350 > __m_slide_331) ? iup_332 : idown_333) * (lt_25350 - __m_slide_331))));
		t_sample slide_25344 = __m_slide_331;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_335 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_336 = (1 / maximum(1, abs(((int)200))));
		__m_slide_334 = fixdenorm((__m_slide_334 + (((m_history_326 > __m_slide_334) ? iup_335 : idown_336) * (m_history_326 - __m_slide_334))));
		t_sample slide_25356 = __m_slide_334;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_338 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_339 = (1 / maximum(1, abs(((int)200))));
		__m_slide_337 = fixdenorm((__m_slide_337 + (((m_history_325 > __m_slide_337) ? iup_338 : idown_339) * (m_history_325 - __m_slide_337))));
		t_sample slide_25345 = __m_slide_337;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_327 * min_25353);
		t_sample mina_340 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_340) ? ((int)1) : mina_340);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_323 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_327);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_323 = y2_next_25373;
		m_y_327 = y1_next_25377;
		m_history_326 = history_25372_next_25376;
		m_history_325 = history_25346_next_25375;
		m_history_324 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_341(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_348 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_349 = (1 / maximum(1, abs(((int)200))));
		__m_slide_347 = fixdenorm((__m_slide_347 + (((m_history_343 > __m_slide_347) ? iup_348 : idown_349) * (m_history_343 - __m_slide_347))));
		t_sample slide_25355 = __m_slide_347;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_343);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_344);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_345);
		int lt_25350 = (id < arg_25383);
		t_sample iup_351 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_352 = (1 / maximum(1, abs(((int)200))));
		__m_slide_350 = fixdenorm((__m_slide_350 + (((lt_25350 > __m_slide_350) ? iup_351 : idown_352) * (lt_25350 - __m_slide_350))));
		t_sample slide_25344 = __m_slide_350;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_354 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_355 = (1 / maximum(1, abs(((int)200))));
		__m_slide_353 = fixdenorm((__m_slide_353 + (((m_history_345 > __m_slide_353) ? iup_354 : idown_355) * (m_history_345 - __m_slide_353))));
		t_sample slide_25356 = __m_slide_353;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_357 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_358 = (1 / maximum(1, abs(((int)200))));
		__m_slide_356 = fixdenorm((__m_slide_356 + (((m_history_344 > __m_slide_356) ? iup_357 : idown_358) * (m_history_344 - __m_slide_356))));
		t_sample slide_25345 = __m_slide_356;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_346 * min_25353);
		t_sample mina_359 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_359) ? ((int)1) : mina_359);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_342 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_346);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_342 = y2_next_25373;
		m_y_346 = y1_next_25377;
		m_history_345 = history_25372_next_25376;
		m_history_344 = history_25346_next_25375;
		m_history_343 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_360(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_367 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_368 = (1 / maximum(1, abs(((int)200))));
		__m_slide_366 = fixdenorm((__m_slide_366 + (((m_history_362 > __m_slide_366) ? iup_367 : idown_368) * (m_history_362 - __m_slide_366))));
		t_sample slide_25355 = __m_slide_366;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_362);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_363);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_364);
		int lt_25350 = (id < arg_25383);
		t_sample iup_370 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_371 = (1 / maximum(1, abs(((int)200))));
		__m_slide_369 = fixdenorm((__m_slide_369 + (((lt_25350 > __m_slide_369) ? iup_370 : idown_371) * (lt_25350 - __m_slide_369))));
		t_sample slide_25344 = __m_slide_369;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_373 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_374 = (1 / maximum(1, abs(((int)200))));
		__m_slide_372 = fixdenorm((__m_slide_372 + (((m_history_364 > __m_slide_372) ? iup_373 : idown_374) * (m_history_364 - __m_slide_372))));
		t_sample slide_25356 = __m_slide_372;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_376 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_377 = (1 / maximum(1, abs(((int)200))));
		__m_slide_375 = fixdenorm((__m_slide_375 + (((m_history_363 > __m_slide_375) ? iup_376 : idown_377) * (m_history_363 - __m_slide_375))));
		t_sample slide_25345 = __m_slide_375;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_365 * min_25353);
		t_sample mina_378 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_378) ? ((int)1) : mina_378);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_361 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_365);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_361 = y2_next_25373;
		m_y_365 = y1_next_25377;
		m_history_364 = history_25372_next_25376;
		m_history_363 = history_25346_next_25375;
		m_history_362 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_379(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_386 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_387 = (1 / maximum(1, abs(((int)200))));
		__m_slide_385 = fixdenorm((__m_slide_385 + (((m_history_381 > __m_slide_385) ? iup_386 : idown_387) * (m_history_381 - __m_slide_385))));
		t_sample slide_25355 = __m_slide_385;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_381);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_382);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_383);
		int lt_25350 = (id < arg_25383);
		t_sample iup_389 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_390 = (1 / maximum(1, abs(((int)200))));
		__m_slide_388 = fixdenorm((__m_slide_388 + (((lt_25350 > __m_slide_388) ? iup_389 : idown_390) * (lt_25350 - __m_slide_388))));
		t_sample slide_25344 = __m_slide_388;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_392 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_393 = (1 / maximum(1, abs(((int)200))));
		__m_slide_391 = fixdenorm((__m_slide_391 + (((m_history_383 > __m_slide_391) ? iup_392 : idown_393) * (m_history_383 - __m_slide_391))));
		t_sample slide_25356 = __m_slide_391;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_395 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_396 = (1 / maximum(1, abs(((int)200))));
		__m_slide_394 = fixdenorm((__m_slide_394 + (((m_history_382 > __m_slide_394) ? iup_395 : idown_396) * (m_history_382 - __m_slide_394))));
		t_sample slide_25345 = __m_slide_394;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_384 * min_25353);
		t_sample mina_397 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_397) ? ((int)1) : mina_397);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_380 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_384);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_380 = y2_next_25373;
		m_y_384 = y1_next_25377;
		m_history_383 = history_25372_next_25376;
		m_history_382 = history_25346_next_25375;
		m_history_381 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_398(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_405 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_406 = (1 / maximum(1, abs(((int)200))));
		__m_slide_404 = fixdenorm((__m_slide_404 + (((m_history_400 > __m_slide_404) ? iup_405 : idown_406) * (m_history_400 - __m_slide_404))));
		t_sample slide_25355 = __m_slide_404;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_400);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_401);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_402);
		int lt_25350 = (id < arg_25383);
		t_sample iup_408 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_409 = (1 / maximum(1, abs(((int)200))));
		__m_slide_407 = fixdenorm((__m_slide_407 + (((lt_25350 > __m_slide_407) ? iup_408 : idown_409) * (lt_25350 - __m_slide_407))));
		t_sample slide_25344 = __m_slide_407;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_411 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_412 = (1 / maximum(1, abs(((int)200))));
		__m_slide_410 = fixdenorm((__m_slide_410 + (((m_history_402 > __m_slide_410) ? iup_411 : idown_412) * (m_history_402 - __m_slide_410))));
		t_sample slide_25356 = __m_slide_410;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_414 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_415 = (1 / maximum(1, abs(((int)200))));
		__m_slide_413 = fixdenorm((__m_slide_413 + (((m_history_401 > __m_slide_413) ? iup_414 : idown_415) * (m_history_401 - __m_slide_413))));
		t_sample slide_25345 = __m_slide_413;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_403 * min_25353);
		t_sample mina_416 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_416) ? ((int)1) : mina_416);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_399 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_403);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_399 = y2_next_25373;
		m_y_403 = y1_next_25377;
		m_history_402 = history_25372_next_25376;
		m_history_401 = history_25346_next_25375;
		m_history_400 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_417(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_424 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_425 = (1 / maximum(1, abs(((int)200))));
		__m_slide_423 = fixdenorm((__m_slide_423 + (((m_history_419 > __m_slide_423) ? iup_424 : idown_425) * (m_history_419 - __m_slide_423))));
		t_sample slide_25355 = __m_slide_423;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_419);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_420);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_421);
		int lt_25350 = (id < arg_25383);
		t_sample iup_427 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_428 = (1 / maximum(1, abs(((int)200))));
		__m_slide_426 = fixdenorm((__m_slide_426 + (((lt_25350 > __m_slide_426) ? iup_427 : idown_428) * (lt_25350 - __m_slide_426))));
		t_sample slide_25344 = __m_slide_426;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_430 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_431 = (1 / maximum(1, abs(((int)200))));
		__m_slide_429 = fixdenorm((__m_slide_429 + (((m_history_421 > __m_slide_429) ? iup_430 : idown_431) * (m_history_421 - __m_slide_429))));
		t_sample slide_25356 = __m_slide_429;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_433 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_434 = (1 / maximum(1, abs(((int)200))));
		__m_slide_432 = fixdenorm((__m_slide_432 + (((m_history_420 > __m_slide_432) ? iup_433 : idown_434) * (m_history_420 - __m_slide_432))));
		t_sample slide_25345 = __m_slide_432;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_422 * min_25353);
		t_sample mina_435 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_435) ? ((int)1) : mina_435);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_418 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_422);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_418 = y2_next_25373;
		m_y_422 = y1_next_25377;
		m_history_421 = history_25372_next_25376;
		m_history_420 = history_25346_next_25375;
		m_history_419 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_436(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_443 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_444 = (1 / maximum(1, abs(((int)200))));
		__m_slide_442 = fixdenorm((__m_slide_442 + (((m_history_438 > __m_slide_442) ? iup_443 : idown_444) * (m_history_438 - __m_slide_442))));
		t_sample slide_25355 = __m_slide_442;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_438);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_439);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_440);
		int lt_25350 = (id < arg_25383);
		t_sample iup_446 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_447 = (1 / maximum(1, abs(((int)200))));
		__m_slide_445 = fixdenorm((__m_slide_445 + (((lt_25350 > __m_slide_445) ? iup_446 : idown_447) * (lt_25350 - __m_slide_445))));
		t_sample slide_25344 = __m_slide_445;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_449 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_450 = (1 / maximum(1, abs(((int)200))));
		__m_slide_448 = fixdenorm((__m_slide_448 + (((m_history_440 > __m_slide_448) ? iup_449 : idown_450) * (m_history_440 - __m_slide_448))));
		t_sample slide_25356 = __m_slide_448;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_452 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_453 = (1 / maximum(1, abs(((int)200))));
		__m_slide_451 = fixdenorm((__m_slide_451 + (((m_history_439 > __m_slide_451) ? iup_452 : idown_453) * (m_history_439 - __m_slide_451))));
		t_sample slide_25345 = __m_slide_451;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_441 * min_25353);
		t_sample mina_454 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_454) ? ((int)1) : mina_454);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_437 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_441);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_437 = y2_next_25373;
		m_y_441 = y1_next_25377;
		m_history_440 = history_25372_next_25376;
		m_history_439 = history_25346_next_25375;
		m_history_438 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_455(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_462 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_463 = (1 / maximum(1, abs(((int)200))));
		__m_slide_461 = fixdenorm((__m_slide_461 + (((m_history_457 > __m_slide_461) ? iup_462 : idown_463) * (m_history_457 - __m_slide_461))));
		t_sample slide_25355 = __m_slide_461;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_457);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_458);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_459);
		int lt_25350 = (id < arg_25383);
		t_sample iup_465 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_466 = (1 / maximum(1, abs(((int)200))));
		__m_slide_464 = fixdenorm((__m_slide_464 + (((lt_25350 > __m_slide_464) ? iup_465 : idown_466) * (lt_25350 - __m_slide_464))));
		t_sample slide_25344 = __m_slide_464;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_468 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_469 = (1 / maximum(1, abs(((int)200))));
		__m_slide_467 = fixdenorm((__m_slide_467 + (((m_history_459 > __m_slide_467) ? iup_468 : idown_469) * (m_history_459 - __m_slide_467))));
		t_sample slide_25356 = __m_slide_467;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_471 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_472 = (1 / maximum(1, abs(((int)200))));
		__m_slide_470 = fixdenorm((__m_slide_470 + (((m_history_458 > __m_slide_470) ? iup_471 : idown_472) * (m_history_458 - __m_slide_470))));
		t_sample slide_25345 = __m_slide_470;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_460 * min_25353);
		t_sample mina_473 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_473) ? ((int)1) : mina_473);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_456 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_460);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_456 = y2_next_25373;
		m_y_460 = y1_next_25377;
		m_history_459 = history_25372_next_25376;
		m_history_458 = history_25346_next_25375;
		m_history_457 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_474(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_481 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_482 = (1 / maximum(1, abs(((int)200))));
		__m_slide_480 = fixdenorm((__m_slide_480 + (((m_history_476 > __m_slide_480) ? iup_481 : idown_482) * (m_history_476 - __m_slide_480))));
		t_sample slide_25355 = __m_slide_480;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_476);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_477);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_478);
		int lt_25350 = (id < arg_25383);
		t_sample iup_484 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_485 = (1 / maximum(1, abs(((int)200))));
		__m_slide_483 = fixdenorm((__m_slide_483 + (((lt_25350 > __m_slide_483) ? iup_484 : idown_485) * (lt_25350 - __m_slide_483))));
		t_sample slide_25344 = __m_slide_483;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_487 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_488 = (1 / maximum(1, abs(((int)200))));
		__m_slide_486 = fixdenorm((__m_slide_486 + (((m_history_478 > __m_slide_486) ? iup_487 : idown_488) * (m_history_478 - __m_slide_486))));
		t_sample slide_25356 = __m_slide_486;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_490 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_491 = (1 / maximum(1, abs(((int)200))));
		__m_slide_489 = fixdenorm((__m_slide_489 + (((m_history_477 > __m_slide_489) ? iup_490 : idown_491) * (m_history_477 - __m_slide_489))));
		t_sample slide_25345 = __m_slide_489;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_479 * min_25353);
		t_sample mina_492 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_492) ? ((int)1) : mina_492);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_475 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_479);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_475 = y2_next_25373;
		m_y_479 = y1_next_25377;
		m_history_478 = history_25372_next_25376;
		m_history_477 = history_25346_next_25375;
		m_history_476 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_493(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_500 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_501 = (1 / maximum(1, abs(((int)200))));
		__m_slide_499 = fixdenorm((__m_slide_499 + (((m_history_495 > __m_slide_499) ? iup_500 : idown_501) * (m_history_495 - __m_slide_499))));
		t_sample slide_25355 = __m_slide_499;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_495);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_496);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_497);
		int lt_25350 = (id < arg_25383);
		t_sample iup_503 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_504 = (1 / maximum(1, abs(((int)200))));
		__m_slide_502 = fixdenorm((__m_slide_502 + (((lt_25350 > __m_slide_502) ? iup_503 : idown_504) * (lt_25350 - __m_slide_502))));
		t_sample slide_25344 = __m_slide_502;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_506 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_507 = (1 / maximum(1, abs(((int)200))));
		__m_slide_505 = fixdenorm((__m_slide_505 + (((m_history_497 > __m_slide_505) ? iup_506 : idown_507) * (m_history_497 - __m_slide_505))));
		t_sample slide_25356 = __m_slide_505;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_509 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_510 = (1 / maximum(1, abs(((int)200))));
		__m_slide_508 = fixdenorm((__m_slide_508 + (((m_history_496 > __m_slide_508) ? iup_509 : idown_510) * (m_history_496 - __m_slide_508))));
		t_sample slide_25345 = __m_slide_508;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_498 * min_25353);
		t_sample mina_511 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_511) ? ((int)1) : mina_511);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_494 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_498);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_494 = y2_next_25373;
		m_y_498 = y1_next_25377;
		m_history_497 = history_25372_next_25376;
		m_history_496 = history_25346_next_25375;
		m_history_495 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_512(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_519 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_520 = (1 / maximum(1, abs(((int)200))));
		__m_slide_518 = fixdenorm((__m_slide_518 + (((m_history_514 > __m_slide_518) ? iup_519 : idown_520) * (m_history_514 - __m_slide_518))));
		t_sample slide_25355 = __m_slide_518;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_514);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_515);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_516);
		int lt_25350 = (id < arg_25383);
		t_sample iup_522 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_523 = (1 / maximum(1, abs(((int)200))));
		__m_slide_521 = fixdenorm((__m_slide_521 + (((lt_25350 > __m_slide_521) ? iup_522 : idown_523) * (lt_25350 - __m_slide_521))));
		t_sample slide_25344 = __m_slide_521;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_525 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_526 = (1 / maximum(1, abs(((int)200))));
		__m_slide_524 = fixdenorm((__m_slide_524 + (((m_history_516 > __m_slide_524) ? iup_525 : idown_526) * (m_history_516 - __m_slide_524))));
		t_sample slide_25356 = __m_slide_524;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_528 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_529 = (1 / maximum(1, abs(((int)200))));
		__m_slide_527 = fixdenorm((__m_slide_527 + (((m_history_515 > __m_slide_527) ? iup_528 : idown_529) * (m_history_515 - __m_slide_527))));
		t_sample slide_25345 = __m_slide_527;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_517 * min_25353);
		t_sample mina_530 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_530) ? ((int)1) : mina_530);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_513 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_517);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_513 = y2_next_25373;
		m_y_517 = y1_next_25377;
		m_history_516 = history_25372_next_25376;
		m_history_515 = history_25346_next_25375;
		m_history_514 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_531(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_538 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_539 = (1 / maximum(1, abs(((int)200))));
		__m_slide_537 = fixdenorm((__m_slide_537 + (((m_history_533 > __m_slide_537) ? iup_538 : idown_539) * (m_history_533 - __m_slide_537))));
		t_sample slide_25355 = __m_slide_537;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_533);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_534);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_535);
		int lt_25350 = (id < arg_25383);
		t_sample iup_541 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_542 = (1 / maximum(1, abs(((int)200))));
		__m_slide_540 = fixdenorm((__m_slide_540 + (((lt_25350 > __m_slide_540) ? iup_541 : idown_542) * (lt_25350 - __m_slide_540))));
		t_sample slide_25344 = __m_slide_540;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_544 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_545 = (1 / maximum(1, abs(((int)200))));
		__m_slide_543 = fixdenorm((__m_slide_543 + (((m_history_535 > __m_slide_543) ? iup_544 : idown_545) * (m_history_535 - __m_slide_543))));
		t_sample slide_25356 = __m_slide_543;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_547 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_548 = (1 / maximum(1, abs(((int)200))));
		__m_slide_546 = fixdenorm((__m_slide_546 + (((m_history_534 > __m_slide_546) ? iup_547 : idown_548) * (m_history_534 - __m_slide_546))));
		t_sample slide_25345 = __m_slide_546;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_536 * min_25353);
		t_sample mina_549 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_549) ? ((int)1) : mina_549);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_532 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_536);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_532 = y2_next_25373;
		m_y_536 = y1_next_25377;
		m_history_535 = history_25372_next_25376;
		m_history_534 = history_25346_next_25375;
		m_history_533 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_550(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_557 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_558 = (1 / maximum(1, abs(((int)200))));
		__m_slide_556 = fixdenorm((__m_slide_556 + (((m_history_552 > __m_slide_556) ? iup_557 : idown_558) * (m_history_552 - __m_slide_556))));
		t_sample slide_25355 = __m_slide_556;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_552);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_553);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_554);
		int lt_25350 = (id < arg_25383);
		t_sample iup_560 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_561 = (1 / maximum(1, abs(((int)200))));
		__m_slide_559 = fixdenorm((__m_slide_559 + (((lt_25350 > __m_slide_559) ? iup_560 : idown_561) * (lt_25350 - __m_slide_559))));
		t_sample slide_25344 = __m_slide_559;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_563 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_564 = (1 / maximum(1, abs(((int)200))));
		__m_slide_562 = fixdenorm((__m_slide_562 + (((m_history_554 > __m_slide_562) ? iup_563 : idown_564) * (m_history_554 - __m_slide_562))));
		t_sample slide_25356 = __m_slide_562;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_566 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_567 = (1 / maximum(1, abs(((int)200))));
		__m_slide_565 = fixdenorm((__m_slide_565 + (((m_history_553 > __m_slide_565) ? iup_566 : idown_567) * (m_history_553 - __m_slide_565))));
		t_sample slide_25345 = __m_slide_565;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_555 * min_25353);
		t_sample mina_568 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_568) ? ((int)1) : mina_568);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_551 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_555);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_551 = y2_next_25373;
		m_y_555 = y1_next_25377;
		m_history_554 = history_25372_next_25376;
		m_history_553 = history_25346_next_25375;
		m_history_552 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_569(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_576 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_577 = (1 / maximum(1, abs(((int)200))));
		__m_slide_575 = fixdenorm((__m_slide_575 + (((m_history_571 > __m_slide_575) ? iup_576 : idown_577) * (m_history_571 - __m_slide_575))));
		t_sample slide_25355 = __m_slide_575;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_571);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_572);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_573);
		int lt_25350 = (id < arg_25383);
		t_sample iup_579 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_580 = (1 / maximum(1, abs(((int)200))));
		__m_slide_578 = fixdenorm((__m_slide_578 + (((lt_25350 > __m_slide_578) ? iup_579 : idown_580) * (lt_25350 - __m_slide_578))));
		t_sample slide_25344 = __m_slide_578;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_582 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_583 = (1 / maximum(1, abs(((int)200))));
		__m_slide_581 = fixdenorm((__m_slide_581 + (((m_history_573 > __m_slide_581) ? iup_582 : idown_583) * (m_history_573 - __m_slide_581))));
		t_sample slide_25356 = __m_slide_581;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_585 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_586 = (1 / maximum(1, abs(((int)200))));
		__m_slide_584 = fixdenorm((__m_slide_584 + (((m_history_572 > __m_slide_584) ? iup_585 : idown_586) * (m_history_572 - __m_slide_584))));
		t_sample slide_25345 = __m_slide_584;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_574 * min_25353);
		t_sample mina_587 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_587) ? ((int)1) : mina_587);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_570 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_574);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_570 = y2_next_25373;
		m_y_574 = y1_next_25377;
		m_history_573 = history_25372_next_25376;
		m_history_572 = history_25346_next_25375;
		m_history_571 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_588(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_595 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_596 = (1 / maximum(1, abs(((int)200))));
		__m_slide_594 = fixdenorm((__m_slide_594 + (((m_history_590 > __m_slide_594) ? iup_595 : idown_596) * (m_history_590 - __m_slide_594))));
		t_sample slide_25355 = __m_slide_594;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_590);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_591);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_592);
		int lt_25350 = (id < arg_25383);
		t_sample iup_598 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_599 = (1 / maximum(1, abs(((int)200))));
		__m_slide_597 = fixdenorm((__m_slide_597 + (((lt_25350 > __m_slide_597) ? iup_598 : idown_599) * (lt_25350 - __m_slide_597))));
		t_sample slide_25344 = __m_slide_597;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_601 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_602 = (1 / maximum(1, abs(((int)200))));
		__m_slide_600 = fixdenorm((__m_slide_600 + (((m_history_592 > __m_slide_600) ? iup_601 : idown_602) * (m_history_592 - __m_slide_600))));
		t_sample slide_25356 = __m_slide_600;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_604 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_605 = (1 / maximum(1, abs(((int)200))));
		__m_slide_603 = fixdenorm((__m_slide_603 + (((m_history_591 > __m_slide_603) ? iup_604 : idown_605) * (m_history_591 - __m_slide_603))));
		t_sample slide_25345 = __m_slide_603;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_593 * min_25353);
		t_sample mina_606 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_606) ? ((int)1) : mina_606);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_589 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_593);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_589 = y2_next_25373;
		m_y_593 = y1_next_25377;
		m_history_592 = history_25372_next_25376;
		m_history_591 = history_25346_next_25375;
		m_history_590 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_607(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_614 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_615 = (1 / maximum(1, abs(((int)200))));
		__m_slide_613 = fixdenorm((__m_slide_613 + (((m_history_609 > __m_slide_613) ? iup_614 : idown_615) * (m_history_609 - __m_slide_613))));
		t_sample slide_25355 = __m_slide_613;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_609);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_610);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_611);
		int lt_25350 = (id < arg_25383);
		t_sample iup_617 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_618 = (1 / maximum(1, abs(((int)200))));
		__m_slide_616 = fixdenorm((__m_slide_616 + (((lt_25350 > __m_slide_616) ? iup_617 : idown_618) * (lt_25350 - __m_slide_616))));
		t_sample slide_25344 = __m_slide_616;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_620 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_621 = (1 / maximum(1, abs(((int)200))));
		__m_slide_619 = fixdenorm((__m_slide_619 + (((m_history_611 > __m_slide_619) ? iup_620 : idown_621) * (m_history_611 - __m_slide_619))));
		t_sample slide_25356 = __m_slide_619;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_623 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_624 = (1 / maximum(1, abs(((int)200))));
		__m_slide_622 = fixdenorm((__m_slide_622 + (((m_history_610 > __m_slide_622) ? iup_623 : idown_624) * (m_history_610 - __m_slide_622))));
		t_sample slide_25345 = __m_slide_622;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_612 * min_25353);
		t_sample mina_625 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_625) ? ((int)1) : mina_625);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_608 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_612);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_608 = y2_next_25373;
		m_y_612 = y1_next_25377;
		m_history_611 = history_25372_next_25376;
		m_history_610 = history_25346_next_25375;
		m_history_609 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_626(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_633 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_634 = (1 / maximum(1, abs(((int)200))));
		__m_slide_632 = fixdenorm((__m_slide_632 + (((m_history_628 > __m_slide_632) ? iup_633 : idown_634) * (m_history_628 - __m_slide_632))));
		t_sample slide_25355 = __m_slide_632;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_628);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_629);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_630);
		int lt_25350 = (id < arg_25383);
		t_sample iup_636 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_637 = (1 / maximum(1, abs(((int)200))));
		__m_slide_635 = fixdenorm((__m_slide_635 + (((lt_25350 > __m_slide_635) ? iup_636 : idown_637) * (lt_25350 - __m_slide_635))));
		t_sample slide_25344 = __m_slide_635;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_639 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_640 = (1 / maximum(1, abs(((int)200))));
		__m_slide_638 = fixdenorm((__m_slide_638 + (((m_history_630 > __m_slide_638) ? iup_639 : idown_640) * (m_history_630 - __m_slide_638))));
		t_sample slide_25356 = __m_slide_638;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_642 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_643 = (1 / maximum(1, abs(((int)200))));
		__m_slide_641 = fixdenorm((__m_slide_641 + (((m_history_629 > __m_slide_641) ? iup_642 : idown_643) * (m_history_629 - __m_slide_641))));
		t_sample slide_25345 = __m_slide_641;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_631 * min_25353);
		t_sample mina_644 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_644) ? ((int)1) : mina_644);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_627 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_631);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_627 = y2_next_25373;
		m_y_631 = y1_next_25377;
		m_history_630 = history_25372_next_25376;
		m_history_629 = history_25346_next_25375;
		m_history_628 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample earth_resonator_d_i_d_d_d_i_i_645(t_sample arg_25378, int arg_25379, t_sample arg_25380, t_sample arg_25381, t_sample arg_25382, int arg_25383, int id) {
		t_sample iup_652 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_653 = (1 / maximum(1, abs(((int)200))));
		__m_slide_651 = fixdenorm((__m_slide_651 + (((m_history_647 > __m_slide_651) ? iup_652 : idown_653) * (m_history_647 - __m_slide_651))));
		t_sample slide_25355 = __m_slide_651;
		int eq_25360 = (id == arg_25379);
		t_sample switch_25358 = (eq_25360 ? arg_25381 : m_history_647);
		t_sample switch_25347 = (eq_25360 ? arg_25382 : m_history_648);
		t_sample switch_25359 = (eq_25360 ? arg_25380 : m_history_649);
		int lt_25350 = (id < arg_25383);
		t_sample iup_655 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_656 = (1 / maximum(1, abs(((int)200))));
		__m_slide_654 = fixdenorm((__m_slide_654 + (((lt_25350 > __m_slide_654) ? iup_655 : idown_656) * (lt_25350 - __m_slide_654))));
		t_sample slide_25344 = __m_slide_654;
		t_sample mul_25343 = (arg_25378 * slide_25344);
		t_sample iup_658 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_659 = (1 / maximum(1, abs(((int)200))));
		__m_slide_657 = fixdenorm((__m_slide_657 + (((m_history_649 > __m_slide_657) ? iup_658 : idown_659) * (m_history_649 - __m_slide_657))));
		t_sample slide_25356 = __m_slide_657;
		t_sample cos_25371 = cos(slide_25356);
		t_sample iup_661 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_662 = (1 / maximum(1, abs(((int)200))));
		__m_slide_660 = fixdenorm((__m_slide_660 + (((m_history_648 > __m_slide_660) ? iup_661 : idown_662) * (m_history_648 - __m_slide_660))));
		t_sample slide_25345 = __m_slide_660;
		t_sample mul_25349 = (slide_25345 * (-1));
		t_sample exp_25368 = exp(mul_25349);
		t_sample mul_25367 = (exp_25368 * (-1));
		t_sample mul_25351 = (slide_25345 * ((t_sample)0.5));
		t_sample exp_25348 = exp(mul_25351);
		t_sample mul_25370 = (cos_25371 * exp_25348);
		t_sample mul_25369 = (mul_25370 * ((int)2));
		t_sample min_25353 = ((((t_sample)1.9999) < mul_25369) ? ((t_sample)1.9999) : mul_25369);
		t_sample mul_25364 = (m_y_650 * min_25353);
		t_sample mina_663 = (mul_25367 + mul_25369);
		t_sample min_25354 = ((((int)1) < mina_663) ? ((int)1) : mina_663);
		t_sample rsub_25366 = (((int)1) - min_25354);
		t_sample mul_25365 = (mul_25343 * rsub_25366);
		t_sample sub_25352 = (min_25354 - min_25353);
		t_sample mul_25363 = (m_y_646 * sub_25352);
		t_sample add_25362 = (((mul_25363 + mul_25364) + mul_25365) + ((int)0));
		t_sample mul_25361 = (slide_25355 * add_25362);
		t_sample y2_next_25373 = fixdenorm(m_y_650);
		t_sample history_25357_next_25374 = fixdenorm(switch_25358);
		t_sample history_25346_next_25375 = fixdenorm(switch_25347);
		t_sample history_25372_next_25376 = fixdenorm(switch_25359);
		t_sample y1_next_25377 = fixdenorm(add_25362);
		m_y_646 = y2_next_25373;
		m_y_650 = y1_next_25377;
		m_history_649 = history_25372_next_25376;
		m_history_648 = history_25346_next_25375;
		m_history_647 = history_25357_next_25374;
		return mul_25361;
		
	};
	inline t_sample go_quantize_d_i_i_i_i_i(t_sample arg_25338, int arg_25339, int arg_25340, int arg_25341, int inversion, int transposition) {
		int min_25337 = ((arg_25339 < ((int)1)) ? ((int)1) : arg_25339);
		t_sample mul_25336 = (arg_25338 * min_25337);
		t_sample add_25335 = (mul_25336 + inversion);
		t_sample round_25330 = round(add_25335);
		t_sample div_25334 = safediv(round_25330, min_25337);
		t_sample mul_25333 = (div_25334 * arg_25340);
		t_sample add_25332 = (mul_25333 + arg_25341);
		t_sample round_25329 = round(add_25332);
		t_sample div_25331 = safediv(round_25329, inversion);
		return div_25331;
		
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 12;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 20; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2", "led1", "led2", "led3", "led4", "led5", "led6", "led7", "led8", "cvout1", "cvout2" };

/// Invoke the signal process of a State object

int perform(CommonState *cself, t_sample **ins, long numins, t_sample **outs, long numouts, long n) {
	State* self = (State *)cself;
	return self->perform(ins, outs, n);
}

/// Reset all parameters and stateful operators of a State object

void reset(CommonState *cself) {
	State* self = (State *)cself;
	self->reset(cself->sr, cself->vs);
}

/// Set a parameter of a State object

void setparameter(CommonState *cself, long index, t_param value, void *ref) {
	State *self = (State *)cself;
	switch (index) {
		case 0: self->set_amps(ref); break;
		case 1: self->set_bws(ref); break;
		case 2: self->set_cvin1(value); break;
		case 3: self->set_fqs(ref); break;
		case 4: self->set_gate1(value); break;
		case 5: self->set_knob1(value); break;
		case 6: self->set_knob2_amps(value); break;
		case 7: self->set_knob3(value); break;
		case 8: self->set_knob4_voices(value); break;
		case 9: self->set_knob5_MIDIoffset(value); break;
		case 10: self->set_knob6_wetdry(value); break;
		case 11: self->set_noise(ref); break;
		case 12: self->set_sw1(value); break;
		case 13: self->set_sw2(value); break;
		case 14: self->set_sw3(value); break;
		case 15: self->set_sw4(value); break;
		case 16: self->set_sw5(value); break;
		case 17: self->set_sw6(value); break;
		case 18: self->set_sw7(value); break;
		case 19: self->set_sw8(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		
		
		case 2: *value = self->m_cvin_18; break;
		
		case 4: *value = self->m_gate_19; break;
		case 5: *value = self->m_knob_31; break;
		case 6: *value = self->m_knob2_amps_28; break;
		case 7: *value = self->m_knob_35; break;
		case 8: *value = self->m_knob4_voices_30; break;
		case 9: *value = self->m_knob5_MIDIoffset_34; break;
		case 10: *value = self->m_knob6_wetdry_24; break;
		
		case 12: *value = self->m_sw_29; break;
		case 13: *value = self->m_sw_23; break;
		case 14: *value = self->m_sw_22; break;
		case 15: *value = self->m_sw_36; break;
		case 16: *value = self->m_sw_26; break;
		case 17: *value = self->m_sw_21; break;
		case 18: *value = self->m_sw_20; break;
		case 19: *value = self->m_sw_25; break;
		
		default: break;
	}
}

/// Get the name of a parameter of a State object

const char *getparametername(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].name;
	}
	return 0;
}

/// Get the minimum value of a parameter of a State object

t_param getparametermin(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmin;
	}
	return 0;
}

/// Get the maximum value of a parameter of a State object

t_param getparametermax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmax;
	}
	return 0;
}

/// Get parameter of a State object has a minimum and maximum value

char getparameterhasminmax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].hasminmax;
	}
	return 0;
}

/// Get the units of a parameter of a State object

const char *getparameterunits(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].units;
	}
	return 0;
}

/// Get the size of the state of all parameters of a State object

size_t getstatesize(CommonState *cself) {
	return genlib_getstatesize(cself, &getparameter);
}

/// Get the state of all parameters of a State object

short getstate(CommonState *cself, char *state) {
	return genlib_getstate(cself, state, &getparameter);
}

/// set the state of all parameters of a State object

short setstate(CommonState *cself, const char *state) {
	return genlib_setstate(cself, state, &setparameter);
}

/// Allocate and configure a new State object and it's internal CommonState:

void *create(t_param sr, long vs) {
	State *self = new State;
	self->reset(sr, vs);
	ParamInfo *pi;
	self->__commonstate.inputnames = gen_kernel_innames;
	self->__commonstate.outputnames = gen_kernel_outnames;
	self->__commonstate.numins = gen_kernel_numins;
	self->__commonstate.numouts = gen_kernel_numouts;
	self->__commonstate.sr = sr;
	self->__commonstate.vs = vs;
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(20 * sizeof(ParamInfo));
	self->__commonstate.numparams = 20;
	// initialize parameter 0 ("m_amps_32")
	pi = self->__commonstate.params + 0;
	pi->name = "amps";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_bws_27")
	pi = self->__commonstate.params + 1;
	pi->name = "bws";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_cvin_18")
	pi = self->__commonstate.params + 2;
	pi->name = "cvin1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cvin_18;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_fqs_37")
	pi = self->__commonstate.params + 3;
	pi->name = "fqs";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_gate_19")
	pi = self->__commonstate.params + 4;
	pi->name = "gate1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_knob_31")
	pi = self->__commonstate.params + 5;
	pi->name = "knob1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_31;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_knob2_amps_28")
	pi = self->__commonstate.params + 6;
	pi->name = "knob2_amps";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob2_amps_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_knob_35")
	pi = self->__commonstate.params + 7;
	pi->name = "knob3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_35;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 20;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_knob4_voices_30")
	pi = self->__commonstate.params + 8;
	pi->name = "knob4_voices";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_voices_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 33;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_knob5_MIDIoffset_34")
	pi = self->__commonstate.params + 9;
	pi->name = "knob5_MIDIoffset";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_MIDIoffset_34;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 32;
	pi->outputmax = 103;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_knob6_wetdry_24")
	pi = self->__commonstate.params + 10;
	pi->name = "knob6_wetdry";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_wetdry_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_noise_33")
	pi = self->__commonstate.params + 11;
	pi->name = "noise";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_sw_29")
	pi = self->__commonstate.params + 12;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_29;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_sw_23")
	pi = self->__commonstate.params + 13;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_sw_22")
	pi = self->__commonstate.params + 14;
	pi->name = "sw3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_22;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_sw_36")
	pi = self->__commonstate.params + 15;
	pi->name = "sw4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_36;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 16 ("m_sw_26")
	pi = self->__commonstate.params + 16;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 17 ("m_sw_21")
	pi = self->__commonstate.params + 17;
	pi->name = "sw6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 18 ("m_sw_20")
	pi = self->__commonstate.params + 18;
	pi->name = "sw7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 19 ("m_sw_25")
	pi = self->__commonstate.params + 19;
	pi->name = "sw8";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // silo::
