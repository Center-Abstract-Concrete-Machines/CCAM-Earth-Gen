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
	Buffer m_terrain_27;
	Data m_params_22;
	Delay m_delay_6;
	Delay m_delay_8;
	Delay m_delay_5;
	Delay m_delay_4;
	Delay m_delay_10;
	Delay m_delay_11;
	Delay m_delay_7;
	Delay m_delay_9;
	int __loopcount;
	int __exception;
	int vectorsize;
	t_sample __m_slide_217;
	t_sample __m_slide_220;
	t_sample __m_slide_223;
	t_sample m_history_215;
	t_sample m_y_216;
	t_sample m_history_213;
	t_sample m_history_214;
	t_sample __m_slide_226;
	t_sample m_y_235;
	t_sample m_history_232;
	t_sample __m_slide_242;
	t_sample __m_slide_245;
	t_sample m_y_250;
	t_sample m_y_231;
	t_sample __m_slide_239;
	t_sample m_history_234;
	t_sample __m_slide_236;
	t_sample m_history_233;
	t_sample m_y_212;
	t_sample m_y_197;
	t_sample __m_slide_204;
	t_sample m_history_176;
	t_sample m_history_177;
	t_sample m_y_178;
	t_sample __m_slide_179;
	t_sample m_history_175;
	t_sample __m_slide_169;
	t_sample m_y_174;
	t_sample __m_slide_166;
	t_sample __m_slide_207;
	t_sample __m_slide_182;
	t_sample __m_slide_188;
	t_sample m_history_251;
	t_sample __m_slide_198;
	t_sample __m_slide_201;
	t_sample __m_slide_185;
	t_sample m_history_196;
	t_sample m_history_194;
	t_sample m_history_195;
	t_sample m_y_193;
	t_sample m_history_252;
	t_sample __m_slide_264;
	t_sample m_y_254;
	t_sample m_history_310;
	t_sample m_y_311;
	t_sample __m_slide_312;
	t_sample __m_slide_315;
	t_sample m_history_309;
	t_sample m_y_307;
	t_sample m_history_308;
	t_sample __m_slide_302;
	t_sample __m_slide_299;
	t_sample __m_slide_318;
	t_sample m_y_326;
	t_sample __m_slide_331;
	t_sample __m_slide_334;
	t_sample __m_slide_321;
	t_sample m_y_330;
	t_sample m_history_328;
	t_sample m_history_329;
	t_sample m_history_327;
	t_sample m_history_253;
	t_sample __m_slide_296;
	t_sample m_y_292;
	t_sample m_y_269;
	t_sample m_history_270;
	t_sample m_history_271;
	t_sample m_history_272;
	t_sample __m_slide_163;
	t_sample __m_slide_258;
	t_sample __m_slide_261;
	t_sample __m_slide_255;
	t_sample __m_slide_293;
	t_sample m_y_273;
	t_sample __m_slide_277;
	t_sample m_history_290;
	t_sample m_history_291;
	t_sample __m_slide_274;
	t_sample m_history_289;
	t_sample __m_slide_283;
	t_sample m_y_288;
	t_sample __m_slide_280;
	t_sample __m_slide_160;
	t_sample __m_slide_150;
	t_sample m_history_158;
	t_sample m_history_43;
	t_sample m_history_44;
	t_sample m_y_45;
	t_sample __m_slide_46;
	t_sample m_history_42;
	t_sample __m_carry_36;
	t_sample m_y_41;
	t_sample __m_count_34;
	t_sample elapsed;
	t_sample __m_slide_49;
	t_sample __m_slide_55;
	t_sample m_y_64;
	t_sample __m_slide_65;
	t_sample __m_slide_52;
	t_sample m_history_63;
	t_sample m_history_61;
	t_sample m_history_62;
	t_sample m_y_60;
	t_sample __m_slide_68;
	t_sample m_sw_29;
	t_sample m_sw_26;
	t_sample m_gate_12;
	t_sample m_sw_13;
	t_sample m_sw_14;
	t_sample m_sw_15;
	t_sample m_history_3;
	t_sample m_N_1;
	t_sample m_history_2;
	t_sample samplerate;
	t_sample m_sw_28;
	t_sample m_sw_16;
	t_sample m_knob4_voices_18;
	t_sample m_knob_24;
	t_sample m_cvin_25;
	t_sample m_sw_17;
	t_sample m_knob_23;
	t_sample m_knob_20;
	t_sample m_knob_21;
	t_sample m_knob_19;
	t_sample m_y_159;
	t_sample __m_slide_71;
	t_sample m_y_79;
	t_sample __m_slide_131;
	t_sample m_y_136;
	t_sample m_history_137;
	t_sample m_history_138;
	t_sample __m_slide_128;
	t_sample __m_slide_122;
	t_sample __m_slide_125;
	t_sample m_y_121;
	t_sample m_history_120;
	t_sample m_history_139;
	t_sample __m_slide_141;
	t_sample m_history_156;
	t_sample m_history_157;
	t_sample m_y_140;
	t_sample m_y_155;
	t_sample __m_slide_147;
	t_sample __m_slide_337;
	t_sample __m_slide_144;
	t_sample __m_slide_74;
	t_sample m_history_119;
	t_sample m_y_117;
	t_sample __m_slide_84;
	t_sample __m_slide_87;
	t_sample __m_slide_90;
	t_sample __m_slide_93;
	t_sample m_y_83;
	t_sample m_history_81;
	t_sample m_history_82;
	t_sample m_history_80;
	t_sample m_history_118;
	t_sample m_y_98;
	t_sample m_history_100;
	t_sample __m_slide_109;
	t_sample __m_slide_112;
	t_sample m_history_99;
	t_sample __m_slide_106;
	t_sample m_y_102;
	t_sample __m_slide_103;
	t_sample m_history_101;
	t_sample __m_slide_340;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_N_1 = ((int)0);
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
		m_gate_12 = ((int)0);
		m_sw_13 = ((int)0);
		m_sw_14 = ((int)0);
		m_sw_15 = ((int)0);
		m_sw_16 = ((int)0);
		m_sw_17 = ((int)0);
		m_knob4_voices_18 = ((int)4);
		m_knob_19 = ((int)1);
		m_knob_20 = ((int)1);
		m_knob_21 = ((int)0);
		m_params_22.reset("params", ((int)16), ((int)3));
		m_knob_23 = ((int)0);
		m_knob_24 = ((int)0);
		m_cvin_25 = ((int)0);
		m_sw_26 = ((int)0);
		m_terrain_27.reset("terrain");
		m_sw_28 = ((int)0);
		m_sw_29 = ((int)0);
		elapsed = 0;
		__m_count_34 = 0;
		__m_carry_36 = 0;
		m_y_41 = ((int)0);
		m_history_42 = ((int)0);
		m_history_43 = ((int)0);
		m_history_44 = ((int)0);
		m_y_45 = ((int)0);
		__m_slide_46 = 0;
		__m_slide_49 = 0;
		__m_slide_52 = 0;
		__m_slide_55 = 0;
		m_y_60 = ((int)0);
		m_history_61 = ((int)0);
		m_history_62 = ((int)0);
		m_history_63 = ((int)0);
		m_y_64 = ((int)0);
		__m_slide_65 = 0;
		__m_slide_68 = 0;
		__m_slide_71 = 0;
		__m_slide_74 = 0;
		m_y_79 = ((int)0);
		m_history_80 = ((int)0);
		m_history_81 = ((int)0);
		m_history_82 = ((int)0);
		m_y_83 = ((int)0);
		__m_slide_84 = 0;
		__m_slide_87 = 0;
		__m_slide_90 = 0;
		__m_slide_93 = 0;
		m_y_98 = ((int)0);
		m_history_99 = ((int)0);
		m_history_100 = ((int)0);
		m_history_101 = ((int)0);
		m_y_102 = ((int)0);
		__m_slide_103 = 0;
		__m_slide_106 = 0;
		__m_slide_109 = 0;
		__m_slide_112 = 0;
		m_y_117 = ((int)0);
		m_history_118 = ((int)0);
		m_history_119 = ((int)0);
		m_history_120 = ((int)0);
		m_y_121 = ((int)0);
		__m_slide_122 = 0;
		__m_slide_125 = 0;
		__m_slide_128 = 0;
		__m_slide_131 = 0;
		m_y_136 = ((int)0);
		m_history_137 = ((int)0);
		m_history_138 = ((int)0);
		m_history_139 = ((int)0);
		m_y_140 = ((int)0);
		__m_slide_141 = 0;
		__m_slide_144 = 0;
		__m_slide_147 = 0;
		__m_slide_150 = 0;
		m_y_155 = ((int)0);
		m_history_156 = ((int)0);
		m_history_157 = ((int)0);
		m_history_158 = ((int)0);
		m_y_159 = ((int)0);
		__m_slide_160 = 0;
		__m_slide_163 = 0;
		__m_slide_166 = 0;
		__m_slide_169 = 0;
		m_y_174 = ((int)0);
		m_history_175 = ((int)0);
		m_history_176 = ((int)0);
		m_history_177 = ((int)0);
		m_y_178 = ((int)0);
		__m_slide_179 = 0;
		__m_slide_182 = 0;
		__m_slide_185 = 0;
		__m_slide_188 = 0;
		m_y_193 = ((int)0);
		m_history_194 = ((int)0);
		m_history_195 = ((int)0);
		m_history_196 = ((int)0);
		m_y_197 = ((int)0);
		__m_slide_198 = 0;
		__m_slide_201 = 0;
		__m_slide_204 = 0;
		__m_slide_207 = 0;
		m_y_212 = ((int)0);
		m_history_213 = ((int)0);
		m_history_214 = ((int)0);
		m_history_215 = ((int)0);
		m_y_216 = ((int)0);
		__m_slide_217 = 0;
		__m_slide_220 = 0;
		__m_slide_223 = 0;
		__m_slide_226 = 0;
		m_y_231 = ((int)0);
		m_history_232 = ((int)0);
		m_history_233 = ((int)0);
		m_history_234 = ((int)0);
		m_y_235 = ((int)0);
		__m_slide_236 = 0;
		__m_slide_239 = 0;
		__m_slide_242 = 0;
		__m_slide_245 = 0;
		m_y_250 = ((int)0);
		m_history_251 = ((int)0);
		m_history_252 = ((int)0);
		m_history_253 = ((int)0);
		m_y_254 = ((int)0);
		__m_slide_255 = 0;
		__m_slide_258 = 0;
		__m_slide_261 = 0;
		__m_slide_264 = 0;
		m_y_269 = ((int)0);
		m_history_270 = ((int)0);
		m_history_271 = ((int)0);
		m_history_272 = ((int)0);
		m_y_273 = ((int)0);
		__m_slide_274 = 0;
		__m_slide_277 = 0;
		__m_slide_280 = 0;
		__m_slide_283 = 0;
		m_y_288 = ((int)0);
		m_history_289 = ((int)0);
		m_history_290 = ((int)0);
		m_history_291 = ((int)0);
		m_y_292 = ((int)0);
		__m_slide_293 = 0;
		__m_slide_296 = 0;
		__m_slide_299 = 0;
		__m_slide_302 = 0;
		m_y_307 = ((int)0);
		m_history_308 = ((int)0);
		m_history_309 = ((int)0);
		m_history_310 = ((int)0);
		m_y_311 = ((int)0);
		__m_slide_312 = 0;
		__m_slide_315 = 0;
		__m_slide_318 = 0;
		__m_slide_321 = 0;
		m_y_326 = ((int)0);
		m_history_327 = ((int)0);
		m_history_328 = ((int)0);
		m_history_329 = ((int)0);
		m_y_330 = ((int)0);
		__m_slide_331 = 0;
		__m_slide_334 = 0;
		__m_slide_337 = 0;
		__m_slide_340 = 0;
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		const t_sample * __in3 = __ins[2];
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
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__in3 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) || (__out7 == 0) || (__out8 == 0) || (__out9 == 0) || (__out10 == 0) || (__out11 == 0) || (__out12 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		const t_sample in2 = __in2[0];
		m_terrain_27.begin();
		int terrain_dim = m_terrain_27.dim;
		int terrain_channels = m_terrain_27.channels;
		int terrain_dim_6049 = terrain_dim;
		t_sample sqrt_6048 = sqrt(terrain_dim_6049);
		__loopcount = (__n * GENLIB_LOOPCOUNT_BAIL);
		int params_dim = m_params_22.dim;
		int params_channels = m_params_22.channels;
		bool chan_ignore_39 = ((1 < 0) || (1 >= params_channels));
		bool chan_ignore_40 = ((2 < 0) || (2 >= params_channels));
		t_sample N_next_6946 = fixdenorm(sqrt_6048);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in3 = (*(__in3++));
			t_sample out3 = ((int)0);
			t_sample out8 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out9 = ((int)0);
			t_sample out10 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out7 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out11 = ((int)0);
			t_sample out12 = ((int)0);
			if (((elapsed == ((int)1)) || (in3 == ((int)1)))) {
				// for loop initializer;
				int i = ((int)0);
				// for loop condition;
				while ((i < m_N_1)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					// for loop initializer;
					int j = ((int)0);
					// for loop condition;
					while ((j < m_N_1)) {
						// abort processing if an infinite loop is suspected;
						if (((__loopcount--) <= 0)) {
							__exception = GENLIB_ERR_LOOP_OVERFLOW;
							break ;
							
						};
						t_sample x = safediv(j, m_N_1);
						t_sample y = safediv(i, m_N_1);
						t_sample z = fxy_d_d(x, y);
						t_sample index = (j + (i * m_N_1));
						int index_trunc_30 = fixnan(floor(index));
						bool index_ignore_31 = ((index_trunc_30 >= terrain_dim) || (index_trunc_30 < 0));
						if ((!index_ignore_31)) {
							m_terrain_27.write(z, index_trunc_30, 0);
							
						};
						// for loop increment;
						j = (j + ((int)1));
						
					};
					// for loop increment;
					i = (i + ((int)1));
					
				};
				
			};
			// abort processing if an infinite loop is suspected;
			if (((__loopcount--) <= 0)) {
				__exception = GENLIB_ERR_LOOP_OVERFLOW;
				break ;
				
			};
			if (((elapsed == ((int)0)) || (in3 == ((int)1)))) {
				// for loop initializer;
				int c = ((int)0);
				// for loop condition;
				while ((c < ((int)3))) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					// for loop initializer;
					int s = ((int)0);
					// for loop condition;
					while ((s < ((int)16))) {
						// abort processing if an infinite loop is suspected;
						if (((__loopcount--) <= 0)) {
							__exception = GENLIB_ERR_LOOP_OVERFLOW;
							break ;
							
						};
						t_sample noise_6949 = noise();
						t_sample sub_6952 = (noise_6949 - ((int)-1));
						t_sample scale_6948 = ((safepow((sub_6952 * ((t_sample)0.5)), ((int)1)) * ((int)1)) + ((int)0));
						int params_dim = m_params_22.dim;
						int params_channels = m_params_22.channels;
						bool chan_ignore_32 = ((c < 0) || (c >= params_channels));
						bool index_ignore_33 = ((s >= params_dim) || (s < 0));
						if ((!(chan_ignore_32 || index_ignore_33))) {
							m_params_22.write(scale_6948, s, c);
							
						};
						// for loop increment;
						s = (s + ((int)1));
						
					};
					// for loop increment;
					c = (c + ((int)1));
					
				};
				
			};
			__m_count_34 = (((int)0) ? 0 : (fixdenorm(__m_count_34 + ((int)1))));
			int carry_35 = 0;
			if ((((int)0) != 0)) {
				__m_count_34 = 0;
				__m_carry_36 = 0;
				
			} else if (((m_knob4_voices_18 > 0) && (__m_count_34 >= m_knob4_voices_18))) {
				int wraps_37 = (__m_count_34 / m_knob4_voices_18);
				__m_carry_36 = (__m_carry_36 + wraps_37);
				__m_count_34 = (__m_count_34 - (wraps_37 * m_knob4_voices_18));
				carry_35 = 1;
				
			};
			int i_6945 = __m_count_34;
			bool index_ignore_38 = ((i_6945 >= params_dim) || (i_6945 < 0));
			// samples params channel 1;
			// samples params channel 2;
			// samples params channel 3;
			t_sample freq = (index_ignore_38 ? 0 : m_params_22.read(i_6945, 0));
			t_sample a = ((chan_ignore_39 || index_ignore_38) ? 0 : m_params_22.read(i_6945, 1));
			t_sample bw = ((chan_ignore_40 || index_ignore_38) ? 0 : m_params_22.read(i_6945, 2));
			t_sample sub_6956 = (freq - ((int)0));
			t_sample scale_6953 = ((safepow((sub_6956 * ((t_sample)1)), ((int)1)) * ((int)700)) + ((int)300));
			t_sample f = ((scale_6953 * ((t_sample)6.2831853071796)) * ((t_sample)2.2675736961451e-05));
			t_sample sub_6960 = (bw - ((int)0));
			t_sample scale_6957 = ((safepow((sub_6960 * ((t_sample)1)), ((int)2)) * ((t_sample)9.5)) + ((t_sample)0.5));
			t_sample b = ((scale_6957 * ((t_sample)6.2831853071796)) * ((t_sample)2.2675736961451e-05));
			t_sample expr_6963 = (((int)0) + gen_resonator_d_i_d_d_d_d_i(in1, i_6945, f, a, b, m_knob4_voices_18, ((int)0)));
			t_sample expr_6964 = (expr_6963 + gen_resonator_d_i_d_d_d_d_i_59(in1, i_6945, f, a, b, m_knob4_voices_18, ((int)1)));
			t_sample expr_6965 = (expr_6964 + gen_resonator_d_i_d_d_d_d_i_78(in1, i_6945, f, a, b, m_knob4_voices_18, ((int)2)));
			t_sample expr_6966 = (expr_6965 + gen_resonator_d_i_d_d_d_d_i_97(in1, i_6945, f, a, b, m_knob4_voices_18, ((int)3)));
			t_sample expr_6967 = (expr_6966 + gen_resonator_d_i_d_d_d_d_i_116(in1, i_6945, f, a, b, m_knob4_voices_18, ((int)4)));
			t_sample expr_6968 = (expr_6967 + gen_resonator_d_i_d_d_d_d_i_135(in1, i_6945, f, a, b, m_knob4_voices_18, ((int)5)));
			t_sample expr_6969 = (expr_6968 + gen_resonator_d_i_d_d_d_d_i_154(in1, i_6945, f, a, b, m_knob4_voices_18, ((int)6)));
			t_sample expr_6970 = (expr_6969 + gen_resonator_d_i_d_d_d_d_i_173(in1, i_6945, f, a, b, m_knob4_voices_18, ((int)7)));
			t_sample expr_6971 = (expr_6970 + gen_resonator_d_i_d_d_d_d_i_192(in1, i_6945, f, a, b, m_knob4_voices_18, ((int)8)));
			t_sample expr_6972 = (expr_6971 + gen_resonator_d_i_d_d_d_d_i_211(in1, i_6945, f, a, b, m_knob4_voices_18, ((int)9)));
			t_sample expr_6973 = (expr_6972 + gen_resonator_d_i_d_d_d_d_i_230(in1, i_6945, f, a, b, m_knob4_voices_18, ((int)10)));
			t_sample expr_6974 = (expr_6973 + gen_resonator_d_i_d_d_d_d_i_249(in1, i_6945, f, a, b, m_knob4_voices_18, ((int)11)));
			t_sample expr_6975 = (expr_6974 + gen_resonator_d_i_d_d_d_d_i_268(in1, i_6945, f, a, b, m_knob4_voices_18, ((int)12)));
			t_sample expr_6976 = (expr_6975 + gen_resonator_d_i_d_d_d_d_i_287(in1, i_6945, f, a, b, m_knob4_voices_18, ((int)13)));
			t_sample expr_6977 = (expr_6976 + gen_resonator_d_i_d_d_d_d_i_306(in1, i_6945, f, a, b, m_knob4_voices_18, ((int)14)));
			t_sample expr_6978 = (expr_6977 + gen_resonator_d_i_d_d_d_d_i_325(in1, i_6945, f, a, b, m_knob4_voices_18, ((int)15)));
			t_sample mul_6051 = (expr_6978 * ((t_sample)0.4));
			t_sample tap_6085 = m_delay_11.read_step(((int)8269));
			t_sample tap_6058 = m_delay_10.read_step(((int)3571));
			t_sample tap_6103 = m_delay_9.read_step(((int)4447));
			t_sample mul_6083 = (tap_6085 * ((t_sample)0.5));
			t_sample tap_6076 = m_delay_8.read_step(((int)2791));
			t_sample mul_6056 = (tap_6058 * ((t_sample)0.5));
			t_sample mix_6961 = (mul_6051 + (((t_sample)0.8) * (m_history_3 - mul_6051)));
			t_sample mix_6105 = mix_6961;
			t_sample add_6082 = (mix_6105 + mul_6083);
			t_sample mul_6081 = (add_6082 * ((t_sample)0.5));
			t_sample sub_6080 = (tap_6085 - mul_6081);
			t_sample gen_6108 = sub_6080;
			t_sample mix_6962 = (mul_6051 + (((t_sample)0.8) * (m_history_2 - mul_6051)));
			t_sample mix_6078 = mix_6962;
			t_sample add_6055 = (mix_6078 + mul_6056);
			t_sample mul_6054 = (add_6055 * ((t_sample)0.5));
			t_sample sub_6053 = (tap_6058 - mul_6054);
			t_sample gen_6109 = sub_6053;
			t_sample tap_6097 = m_delay_7.read_step(((int)7351));
			t_sample mul_6101 = (tap_6103 * ((t_sample)0.5));
			t_sample add_6100 = (add_6082 + mul_6101);
			t_sample mul_6099 = (add_6100 * ((t_sample)0.5));
			t_sample sub_6098 = (tap_6103 - mul_6099);
			t_sample tap_6070 = m_delay_6.read_step(((int)5167));
			t_sample mul_6074 = (tap_6076 * ((t_sample)0.5));
			t_sample add_6073 = (add_6055 + mul_6074);
			t_sample mul_6072 = (add_6073 * ((t_sample)0.5));
			t_sample sub_6071 = (tap_6076 - mul_6072);
			t_sample tap_6091 = m_delay_5.read_step(((int)5419));
			t_sample mul_6095 = (tap_6097 * ((t_sample)0.5));
			t_sample add_6094 = (add_6100 + mul_6095);
			t_sample mul_6093 = (add_6094 * ((t_sample)0.5));
			t_sample sub_6092 = (tap_6097 - mul_6093);
			t_sample tap_6064 = m_delay_4.read_step(((int)3469));
			t_sample mul_6068 = (tap_6070 * ((t_sample)0.5));
			t_sample add_6067 = (add_6073 + mul_6068);
			t_sample mul_6066 = (add_6067 * ((t_sample)0.5));
			t_sample sub_6065 = (tap_6070 - mul_6066);
			t_sample mul_6089 = (tap_6091 * ((t_sample)0.5));
			t_sample add_6088 = (add_6094 + mul_6089);
			t_sample mul_6087 = (add_6088 * ((t_sample)0.5));
			t_sample sub_6086 = (tap_6091 - mul_6087);
			t_sample mul_6062 = (tap_6064 * ((t_sample)0.5));
			t_sample add_6061 = (add_6067 + mul_6062);
			t_sample mul_6060 = (add_6061 * ((t_sample)0.5));
			t_sample sub_6059 = (tap_6064 - mul_6060);
			t_sample history_6104_next_6106 = fixdenorm(sub_6080);
			t_sample history_6077_next_6107 = fixdenorm(sub_6053);
			t_sample out2 = gen_6109;
			t_sample out1 = gen_6108;
			m_delay_11.write(sub_6098);
			m_history_2 = history_6077_next_6107;
			m_history_3 = history_6104_next_6106;
			m_delay_4.write(add_6061);
			m_delay_5.write(add_6088);
			m_delay_6.write(sub_6059);
			m_delay_7.write(sub_6086);
			m_delay_8.write(sub_6065);
			m_delay_9.write(sub_6092);
			m_delay_10.write(sub_6071);
			m_N_1 = N_next_6946;
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
		m_terrain_27.end();
		return __exception;
		
	};
	inline void set_N(t_param _value) {
		m_N_1 = _value;
	};
	inline void set_history_6077(t_param _value) {
		m_history_2 = _value;
	};
	inline void set_history_6104(t_param _value) {
		m_history_3 = _value;
	};
	inline void set_gate1(t_param _value) {
		m_gate_12 = _value;
	};
	inline void set_sw5(t_param _value) {
		m_sw_13 = _value;
	};
	inline void set_sw3(t_param _value) {
		m_sw_14 = _value;
	};
	inline void set_sw8(t_param _value) {
		m_sw_15 = _value;
	};
	inline void set_sw6(t_param _value) {
		m_sw_16 = _value;
	};
	inline void set_sw2(t_param _value) {
		m_sw_17 = _value;
	};
	inline void set_knob4_voices(t_param _value) {
		m_knob4_voices_18 = (_value < 1 ? 1 : (_value > 16 ? 16 : _value));
	};
	inline void set_knob6(t_param _value) {
		m_knob_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5(t_param _value) {
		m_knob_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3(t_param _value) {
		m_knob_21 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_params(void * _value) {
		m_params_22.setbuffer(_value);
	};
	inline void set_knob2(t_param _value) {
		m_knob_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1(t_param _value) {
		m_knob_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_cvin1(t_param _value) {
		m_cvin_25 = _value;
	};
	inline void set_sw4(t_param _value) {
		m_sw_26 = _value;
	};
	inline void set_terrain(void * _value) {
		m_terrain_27.setbuffer(_value);
	};
	inline void set_sw1(t_param _value) {
		m_sw_28 = _value;
	};
	inline void set_sw7(t_param _value) {
		m_sw_29 = _value;
	};
	inline t_sample fxy_d_d(t_sample x, t_sample y) {
		t_sample x1 = ((x * ((int)2)) - ((int)1));
		t_sample x2 = tanh((sin(((((t_sample)6.2831853071796) * x) * (((int)16) + y))) + sin(((((int)8) * ((t_sample)3.1415926535898)) * x))));
		t_sample mix_6947 = (x1 + (y * (x2 - x1)));
		return mix_6947;
		
	};
	inline t_sample gen_resonator_d_i_d_d_d_d_i(t_sample arg_6938, int arg_6939, t_sample arg_6940, t_sample arg_6941, t_sample arg_6942, t_sample voices, int id) {
		t_sample iup_47 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_48 = (1 / maximum(1, abs(((int)200))));
		__m_slide_46 = fixdenorm((__m_slide_46 + (((m_history_42 > __m_slide_46) ? iup_47 : idown_48) * (m_history_42 - __m_slide_46))));
		t_sample slide_6915 = __m_slide_46;
		int eq_6920 = (id == arg_6939);
		t_sample switch_6918 = (eq_6920 ? arg_6941 : m_history_42);
		t_sample switch_6907 = (eq_6920 ? arg_6942 : m_history_43);
		t_sample switch_6919 = (eq_6920 ? arg_6940 : m_history_44);
		int lt_6910 = (id < voices);
		t_sample iup_50 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_51 = (1 / maximum(1, abs(((int)200))));
		__m_slide_49 = fixdenorm((__m_slide_49 + (((lt_6910 > __m_slide_49) ? iup_50 : idown_51) * (lt_6910 - __m_slide_49))));
		t_sample slide_6904 = __m_slide_49;
		t_sample mul_6903 = (arg_6938 * slide_6904);
		t_sample iup_53 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_54 = (1 / maximum(1, abs(((int)200))));
		__m_slide_52 = fixdenorm((__m_slide_52 + (((m_history_44 > __m_slide_52) ? iup_53 : idown_54) * (m_history_44 - __m_slide_52))));
		t_sample slide_6916 = __m_slide_52;
		t_sample cos_6931 = cos(slide_6916);
		t_sample iup_56 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_57 = (1 / maximum(1, abs(((int)200))));
		__m_slide_55 = fixdenorm((__m_slide_55 + (((m_history_43 > __m_slide_55) ? iup_56 : idown_57) * (m_history_43 - __m_slide_55))));
		t_sample slide_6905 = __m_slide_55;
		t_sample mul_6909 = (slide_6905 * ((int)-1));
		t_sample exp_6928 = exp(mul_6909);
		t_sample mul_6927 = (exp_6928 * ((int)-1));
		t_sample mul_6911 = (slide_6905 * ((t_sample)0.5));
		t_sample exp_6908 = exp(mul_6911);
		t_sample mul_6930 = (cos_6931 * exp_6908);
		t_sample mul_6929 = (mul_6930 * ((int)2));
		t_sample min_6913 = ((((t_sample)1.9999) < mul_6929) ? ((t_sample)1.9999) : mul_6929);
		t_sample mul_6924 = (m_y_45 * min_6913);
		t_sample mina_58 = (mul_6927 + mul_6929);
		t_sample min_6914 = ((((int)1) < mina_58) ? ((int)1) : mina_58);
		t_sample rsub_6926 = (((int)1) - min_6914);
		t_sample mul_6925 = (mul_6903 * rsub_6926);
		t_sample sub_6912 = (min_6914 - min_6913);
		t_sample mul_6923 = (m_y_41 * sub_6912);
		t_sample add_6922 = (((mul_6923 + mul_6924) + mul_6925) + ((int)0));
		t_sample mul_6921 = (slide_6915 * add_6922);
		t_sample y2_next_6933 = fixdenorm(m_y_45);
		t_sample history_6917_next_6934 = fixdenorm(switch_6918);
		t_sample history_6906_next_6935 = fixdenorm(switch_6907);
		t_sample history_6932_next_6936 = fixdenorm(switch_6919);
		t_sample y1_next_6937 = fixdenorm(add_6922);
		m_y_41 = y2_next_6933;
		m_y_45 = y1_next_6937;
		m_history_44 = history_6932_next_6936;
		m_history_43 = history_6906_next_6935;
		m_history_42 = history_6917_next_6934;
		return mul_6921;
		
	};
	inline t_sample gen_resonator_d_i_d_d_d_d_i_59(t_sample arg_6938, int arg_6939, t_sample arg_6940, t_sample arg_6941, t_sample arg_6942, t_sample voices, int id) {
		t_sample iup_66 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_67 = (1 / maximum(1, abs(((int)200))));
		__m_slide_65 = fixdenorm((__m_slide_65 + (((m_history_61 > __m_slide_65) ? iup_66 : idown_67) * (m_history_61 - __m_slide_65))));
		t_sample slide_6915 = __m_slide_65;
		int eq_6920 = (id == arg_6939);
		t_sample switch_6918 = (eq_6920 ? arg_6941 : m_history_61);
		t_sample switch_6907 = (eq_6920 ? arg_6942 : m_history_62);
		t_sample switch_6919 = (eq_6920 ? arg_6940 : m_history_63);
		int lt_6910 = (id < voices);
		t_sample iup_69 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_70 = (1 / maximum(1, abs(((int)200))));
		__m_slide_68 = fixdenorm((__m_slide_68 + (((lt_6910 > __m_slide_68) ? iup_69 : idown_70) * (lt_6910 - __m_slide_68))));
		t_sample slide_6904 = __m_slide_68;
		t_sample mul_6903 = (arg_6938 * slide_6904);
		t_sample iup_72 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_73 = (1 / maximum(1, abs(((int)200))));
		__m_slide_71 = fixdenorm((__m_slide_71 + (((m_history_63 > __m_slide_71) ? iup_72 : idown_73) * (m_history_63 - __m_slide_71))));
		t_sample slide_6916 = __m_slide_71;
		t_sample cos_6931 = cos(slide_6916);
		t_sample iup_75 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_76 = (1 / maximum(1, abs(((int)200))));
		__m_slide_74 = fixdenorm((__m_slide_74 + (((m_history_62 > __m_slide_74) ? iup_75 : idown_76) * (m_history_62 - __m_slide_74))));
		t_sample slide_6905 = __m_slide_74;
		t_sample mul_6909 = (slide_6905 * ((int)-1));
		t_sample exp_6928 = exp(mul_6909);
		t_sample mul_6927 = (exp_6928 * ((int)-1));
		t_sample mul_6911 = (slide_6905 * ((t_sample)0.5));
		t_sample exp_6908 = exp(mul_6911);
		t_sample mul_6930 = (cos_6931 * exp_6908);
		t_sample mul_6929 = (mul_6930 * ((int)2));
		t_sample min_6913 = ((((t_sample)1.9999) < mul_6929) ? ((t_sample)1.9999) : mul_6929);
		t_sample mul_6924 = (m_y_64 * min_6913);
		t_sample mina_77 = (mul_6927 + mul_6929);
		t_sample min_6914 = ((((int)1) < mina_77) ? ((int)1) : mina_77);
		t_sample rsub_6926 = (((int)1) - min_6914);
		t_sample mul_6925 = (mul_6903 * rsub_6926);
		t_sample sub_6912 = (min_6914 - min_6913);
		t_sample mul_6923 = (m_y_60 * sub_6912);
		t_sample add_6922 = (((mul_6923 + mul_6924) + mul_6925) + ((int)0));
		t_sample mul_6921 = (slide_6915 * add_6922);
		t_sample y2_next_6933 = fixdenorm(m_y_64);
		t_sample history_6917_next_6934 = fixdenorm(switch_6918);
		t_sample history_6906_next_6935 = fixdenorm(switch_6907);
		t_sample history_6932_next_6936 = fixdenorm(switch_6919);
		t_sample y1_next_6937 = fixdenorm(add_6922);
		m_y_60 = y2_next_6933;
		m_y_64 = y1_next_6937;
		m_history_63 = history_6932_next_6936;
		m_history_62 = history_6906_next_6935;
		m_history_61 = history_6917_next_6934;
		return mul_6921;
		
	};
	inline t_sample gen_resonator_d_i_d_d_d_d_i_78(t_sample arg_6938, int arg_6939, t_sample arg_6940, t_sample arg_6941, t_sample arg_6942, t_sample voices, int id) {
		t_sample iup_85 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_86 = (1 / maximum(1, abs(((int)200))));
		__m_slide_84 = fixdenorm((__m_slide_84 + (((m_history_80 > __m_slide_84) ? iup_85 : idown_86) * (m_history_80 - __m_slide_84))));
		t_sample slide_6915 = __m_slide_84;
		int eq_6920 = (id == arg_6939);
		t_sample switch_6918 = (eq_6920 ? arg_6941 : m_history_80);
		t_sample switch_6907 = (eq_6920 ? arg_6942 : m_history_81);
		t_sample switch_6919 = (eq_6920 ? arg_6940 : m_history_82);
		int lt_6910 = (id < voices);
		t_sample iup_88 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_89 = (1 / maximum(1, abs(((int)200))));
		__m_slide_87 = fixdenorm((__m_slide_87 + (((lt_6910 > __m_slide_87) ? iup_88 : idown_89) * (lt_6910 - __m_slide_87))));
		t_sample slide_6904 = __m_slide_87;
		t_sample mul_6903 = (arg_6938 * slide_6904);
		t_sample iup_91 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_92 = (1 / maximum(1, abs(((int)200))));
		__m_slide_90 = fixdenorm((__m_slide_90 + (((m_history_82 > __m_slide_90) ? iup_91 : idown_92) * (m_history_82 - __m_slide_90))));
		t_sample slide_6916 = __m_slide_90;
		t_sample cos_6931 = cos(slide_6916);
		t_sample iup_94 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_95 = (1 / maximum(1, abs(((int)200))));
		__m_slide_93 = fixdenorm((__m_slide_93 + (((m_history_81 > __m_slide_93) ? iup_94 : idown_95) * (m_history_81 - __m_slide_93))));
		t_sample slide_6905 = __m_slide_93;
		t_sample mul_6909 = (slide_6905 * ((int)-1));
		t_sample exp_6928 = exp(mul_6909);
		t_sample mul_6927 = (exp_6928 * ((int)-1));
		t_sample mul_6911 = (slide_6905 * ((t_sample)0.5));
		t_sample exp_6908 = exp(mul_6911);
		t_sample mul_6930 = (cos_6931 * exp_6908);
		t_sample mul_6929 = (mul_6930 * ((int)2));
		t_sample min_6913 = ((((t_sample)1.9999) < mul_6929) ? ((t_sample)1.9999) : mul_6929);
		t_sample mul_6924 = (m_y_83 * min_6913);
		t_sample mina_96 = (mul_6927 + mul_6929);
		t_sample min_6914 = ((((int)1) < mina_96) ? ((int)1) : mina_96);
		t_sample rsub_6926 = (((int)1) - min_6914);
		t_sample mul_6925 = (mul_6903 * rsub_6926);
		t_sample sub_6912 = (min_6914 - min_6913);
		t_sample mul_6923 = (m_y_79 * sub_6912);
		t_sample add_6922 = (((mul_6923 + mul_6924) + mul_6925) + ((int)0));
		t_sample mul_6921 = (slide_6915 * add_6922);
		t_sample y2_next_6933 = fixdenorm(m_y_83);
		t_sample history_6917_next_6934 = fixdenorm(switch_6918);
		t_sample history_6906_next_6935 = fixdenorm(switch_6907);
		t_sample history_6932_next_6936 = fixdenorm(switch_6919);
		t_sample y1_next_6937 = fixdenorm(add_6922);
		m_y_79 = y2_next_6933;
		m_y_83 = y1_next_6937;
		m_history_82 = history_6932_next_6936;
		m_history_81 = history_6906_next_6935;
		m_history_80 = history_6917_next_6934;
		return mul_6921;
		
	};
	inline t_sample gen_resonator_d_i_d_d_d_d_i_97(t_sample arg_6938, int arg_6939, t_sample arg_6940, t_sample arg_6941, t_sample arg_6942, t_sample voices, int id) {
		t_sample iup_104 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_105 = (1 / maximum(1, abs(((int)200))));
		__m_slide_103 = fixdenorm((__m_slide_103 + (((m_history_99 > __m_slide_103) ? iup_104 : idown_105) * (m_history_99 - __m_slide_103))));
		t_sample slide_6915 = __m_slide_103;
		int eq_6920 = (id == arg_6939);
		t_sample switch_6918 = (eq_6920 ? arg_6941 : m_history_99);
		t_sample switch_6907 = (eq_6920 ? arg_6942 : m_history_100);
		t_sample switch_6919 = (eq_6920 ? arg_6940 : m_history_101);
		int lt_6910 = (id < voices);
		t_sample iup_107 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_108 = (1 / maximum(1, abs(((int)200))));
		__m_slide_106 = fixdenorm((__m_slide_106 + (((lt_6910 > __m_slide_106) ? iup_107 : idown_108) * (lt_6910 - __m_slide_106))));
		t_sample slide_6904 = __m_slide_106;
		t_sample mul_6903 = (arg_6938 * slide_6904);
		t_sample iup_110 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_111 = (1 / maximum(1, abs(((int)200))));
		__m_slide_109 = fixdenorm((__m_slide_109 + (((m_history_101 > __m_slide_109) ? iup_110 : idown_111) * (m_history_101 - __m_slide_109))));
		t_sample slide_6916 = __m_slide_109;
		t_sample cos_6931 = cos(slide_6916);
		t_sample iup_113 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_114 = (1 / maximum(1, abs(((int)200))));
		__m_slide_112 = fixdenorm((__m_slide_112 + (((m_history_100 > __m_slide_112) ? iup_113 : idown_114) * (m_history_100 - __m_slide_112))));
		t_sample slide_6905 = __m_slide_112;
		t_sample mul_6909 = (slide_6905 * ((int)-1));
		t_sample exp_6928 = exp(mul_6909);
		t_sample mul_6927 = (exp_6928 * ((int)-1));
		t_sample mul_6911 = (slide_6905 * ((t_sample)0.5));
		t_sample exp_6908 = exp(mul_6911);
		t_sample mul_6930 = (cos_6931 * exp_6908);
		t_sample mul_6929 = (mul_6930 * ((int)2));
		t_sample min_6913 = ((((t_sample)1.9999) < mul_6929) ? ((t_sample)1.9999) : mul_6929);
		t_sample mul_6924 = (m_y_102 * min_6913);
		t_sample mina_115 = (mul_6927 + mul_6929);
		t_sample min_6914 = ((((int)1) < mina_115) ? ((int)1) : mina_115);
		t_sample rsub_6926 = (((int)1) - min_6914);
		t_sample mul_6925 = (mul_6903 * rsub_6926);
		t_sample sub_6912 = (min_6914 - min_6913);
		t_sample mul_6923 = (m_y_98 * sub_6912);
		t_sample add_6922 = (((mul_6923 + mul_6924) + mul_6925) + ((int)0));
		t_sample mul_6921 = (slide_6915 * add_6922);
		t_sample y2_next_6933 = fixdenorm(m_y_102);
		t_sample history_6917_next_6934 = fixdenorm(switch_6918);
		t_sample history_6906_next_6935 = fixdenorm(switch_6907);
		t_sample history_6932_next_6936 = fixdenorm(switch_6919);
		t_sample y1_next_6937 = fixdenorm(add_6922);
		m_y_98 = y2_next_6933;
		m_y_102 = y1_next_6937;
		m_history_101 = history_6932_next_6936;
		m_history_100 = history_6906_next_6935;
		m_history_99 = history_6917_next_6934;
		return mul_6921;
		
	};
	inline t_sample gen_resonator_d_i_d_d_d_d_i_116(t_sample arg_6938, int arg_6939, t_sample arg_6940, t_sample arg_6941, t_sample arg_6942, t_sample voices, int id) {
		t_sample iup_123 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_124 = (1 / maximum(1, abs(((int)200))));
		__m_slide_122 = fixdenorm((__m_slide_122 + (((m_history_118 > __m_slide_122) ? iup_123 : idown_124) * (m_history_118 - __m_slide_122))));
		t_sample slide_6915 = __m_slide_122;
		int eq_6920 = (id == arg_6939);
		t_sample switch_6918 = (eq_6920 ? arg_6941 : m_history_118);
		t_sample switch_6907 = (eq_6920 ? arg_6942 : m_history_119);
		t_sample switch_6919 = (eq_6920 ? arg_6940 : m_history_120);
		int lt_6910 = (id < voices);
		t_sample iup_126 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_127 = (1 / maximum(1, abs(((int)200))));
		__m_slide_125 = fixdenorm((__m_slide_125 + (((lt_6910 > __m_slide_125) ? iup_126 : idown_127) * (lt_6910 - __m_slide_125))));
		t_sample slide_6904 = __m_slide_125;
		t_sample mul_6903 = (arg_6938 * slide_6904);
		t_sample iup_129 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_130 = (1 / maximum(1, abs(((int)200))));
		__m_slide_128 = fixdenorm((__m_slide_128 + (((m_history_120 > __m_slide_128) ? iup_129 : idown_130) * (m_history_120 - __m_slide_128))));
		t_sample slide_6916 = __m_slide_128;
		t_sample cos_6931 = cos(slide_6916);
		t_sample iup_132 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_133 = (1 / maximum(1, abs(((int)200))));
		__m_slide_131 = fixdenorm((__m_slide_131 + (((m_history_119 > __m_slide_131) ? iup_132 : idown_133) * (m_history_119 - __m_slide_131))));
		t_sample slide_6905 = __m_slide_131;
		t_sample mul_6909 = (slide_6905 * ((int)-1));
		t_sample exp_6928 = exp(mul_6909);
		t_sample mul_6927 = (exp_6928 * ((int)-1));
		t_sample mul_6911 = (slide_6905 * ((t_sample)0.5));
		t_sample exp_6908 = exp(mul_6911);
		t_sample mul_6930 = (cos_6931 * exp_6908);
		t_sample mul_6929 = (mul_6930 * ((int)2));
		t_sample min_6913 = ((((t_sample)1.9999) < mul_6929) ? ((t_sample)1.9999) : mul_6929);
		t_sample mul_6924 = (m_y_121 * min_6913);
		t_sample mina_134 = (mul_6927 + mul_6929);
		t_sample min_6914 = ((((int)1) < mina_134) ? ((int)1) : mina_134);
		t_sample rsub_6926 = (((int)1) - min_6914);
		t_sample mul_6925 = (mul_6903 * rsub_6926);
		t_sample sub_6912 = (min_6914 - min_6913);
		t_sample mul_6923 = (m_y_117 * sub_6912);
		t_sample add_6922 = (((mul_6923 + mul_6924) + mul_6925) + ((int)0));
		t_sample mul_6921 = (slide_6915 * add_6922);
		t_sample y2_next_6933 = fixdenorm(m_y_121);
		t_sample history_6917_next_6934 = fixdenorm(switch_6918);
		t_sample history_6906_next_6935 = fixdenorm(switch_6907);
		t_sample history_6932_next_6936 = fixdenorm(switch_6919);
		t_sample y1_next_6937 = fixdenorm(add_6922);
		m_y_117 = y2_next_6933;
		m_y_121 = y1_next_6937;
		m_history_120 = history_6932_next_6936;
		m_history_119 = history_6906_next_6935;
		m_history_118 = history_6917_next_6934;
		return mul_6921;
		
	};
	inline t_sample gen_resonator_d_i_d_d_d_d_i_135(t_sample arg_6938, int arg_6939, t_sample arg_6940, t_sample arg_6941, t_sample arg_6942, t_sample voices, int id) {
		t_sample iup_142 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_143 = (1 / maximum(1, abs(((int)200))));
		__m_slide_141 = fixdenorm((__m_slide_141 + (((m_history_137 > __m_slide_141) ? iup_142 : idown_143) * (m_history_137 - __m_slide_141))));
		t_sample slide_6915 = __m_slide_141;
		int eq_6920 = (id == arg_6939);
		t_sample switch_6918 = (eq_6920 ? arg_6941 : m_history_137);
		t_sample switch_6907 = (eq_6920 ? arg_6942 : m_history_138);
		t_sample switch_6919 = (eq_6920 ? arg_6940 : m_history_139);
		int lt_6910 = (id < voices);
		t_sample iup_145 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_146 = (1 / maximum(1, abs(((int)200))));
		__m_slide_144 = fixdenorm((__m_slide_144 + (((lt_6910 > __m_slide_144) ? iup_145 : idown_146) * (lt_6910 - __m_slide_144))));
		t_sample slide_6904 = __m_slide_144;
		t_sample mul_6903 = (arg_6938 * slide_6904);
		t_sample iup_148 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_149 = (1 / maximum(1, abs(((int)200))));
		__m_slide_147 = fixdenorm((__m_slide_147 + (((m_history_139 > __m_slide_147) ? iup_148 : idown_149) * (m_history_139 - __m_slide_147))));
		t_sample slide_6916 = __m_slide_147;
		t_sample cos_6931 = cos(slide_6916);
		t_sample iup_151 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_152 = (1 / maximum(1, abs(((int)200))));
		__m_slide_150 = fixdenorm((__m_slide_150 + (((m_history_138 > __m_slide_150) ? iup_151 : idown_152) * (m_history_138 - __m_slide_150))));
		t_sample slide_6905 = __m_slide_150;
		t_sample mul_6909 = (slide_6905 * ((int)-1));
		t_sample exp_6928 = exp(mul_6909);
		t_sample mul_6927 = (exp_6928 * ((int)-1));
		t_sample mul_6911 = (slide_6905 * ((t_sample)0.5));
		t_sample exp_6908 = exp(mul_6911);
		t_sample mul_6930 = (cos_6931 * exp_6908);
		t_sample mul_6929 = (mul_6930 * ((int)2));
		t_sample min_6913 = ((((t_sample)1.9999) < mul_6929) ? ((t_sample)1.9999) : mul_6929);
		t_sample mul_6924 = (m_y_140 * min_6913);
		t_sample mina_153 = (mul_6927 + mul_6929);
		t_sample min_6914 = ((((int)1) < mina_153) ? ((int)1) : mina_153);
		t_sample rsub_6926 = (((int)1) - min_6914);
		t_sample mul_6925 = (mul_6903 * rsub_6926);
		t_sample sub_6912 = (min_6914 - min_6913);
		t_sample mul_6923 = (m_y_136 * sub_6912);
		t_sample add_6922 = (((mul_6923 + mul_6924) + mul_6925) + ((int)0));
		t_sample mul_6921 = (slide_6915 * add_6922);
		t_sample y2_next_6933 = fixdenorm(m_y_140);
		t_sample history_6917_next_6934 = fixdenorm(switch_6918);
		t_sample history_6906_next_6935 = fixdenorm(switch_6907);
		t_sample history_6932_next_6936 = fixdenorm(switch_6919);
		t_sample y1_next_6937 = fixdenorm(add_6922);
		m_y_136 = y2_next_6933;
		m_y_140 = y1_next_6937;
		m_history_139 = history_6932_next_6936;
		m_history_138 = history_6906_next_6935;
		m_history_137 = history_6917_next_6934;
		return mul_6921;
		
	};
	inline t_sample gen_resonator_d_i_d_d_d_d_i_154(t_sample arg_6938, int arg_6939, t_sample arg_6940, t_sample arg_6941, t_sample arg_6942, t_sample voices, int id) {
		t_sample iup_161 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_162 = (1 / maximum(1, abs(((int)200))));
		__m_slide_160 = fixdenorm((__m_slide_160 + (((m_history_156 > __m_slide_160) ? iup_161 : idown_162) * (m_history_156 - __m_slide_160))));
		t_sample slide_6915 = __m_slide_160;
		int eq_6920 = (id == arg_6939);
		t_sample switch_6918 = (eq_6920 ? arg_6941 : m_history_156);
		t_sample switch_6907 = (eq_6920 ? arg_6942 : m_history_157);
		t_sample switch_6919 = (eq_6920 ? arg_6940 : m_history_158);
		int lt_6910 = (id < voices);
		t_sample iup_164 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_165 = (1 / maximum(1, abs(((int)200))));
		__m_slide_163 = fixdenorm((__m_slide_163 + (((lt_6910 > __m_slide_163) ? iup_164 : idown_165) * (lt_6910 - __m_slide_163))));
		t_sample slide_6904 = __m_slide_163;
		t_sample mul_6903 = (arg_6938 * slide_6904);
		t_sample iup_167 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_168 = (1 / maximum(1, abs(((int)200))));
		__m_slide_166 = fixdenorm((__m_slide_166 + (((m_history_158 > __m_slide_166) ? iup_167 : idown_168) * (m_history_158 - __m_slide_166))));
		t_sample slide_6916 = __m_slide_166;
		t_sample cos_6931 = cos(slide_6916);
		t_sample iup_170 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_171 = (1 / maximum(1, abs(((int)200))));
		__m_slide_169 = fixdenorm((__m_slide_169 + (((m_history_157 > __m_slide_169) ? iup_170 : idown_171) * (m_history_157 - __m_slide_169))));
		t_sample slide_6905 = __m_slide_169;
		t_sample mul_6909 = (slide_6905 * ((int)-1));
		t_sample exp_6928 = exp(mul_6909);
		t_sample mul_6927 = (exp_6928 * ((int)-1));
		t_sample mul_6911 = (slide_6905 * ((t_sample)0.5));
		t_sample exp_6908 = exp(mul_6911);
		t_sample mul_6930 = (cos_6931 * exp_6908);
		t_sample mul_6929 = (mul_6930 * ((int)2));
		t_sample min_6913 = ((((t_sample)1.9999) < mul_6929) ? ((t_sample)1.9999) : mul_6929);
		t_sample mul_6924 = (m_y_159 * min_6913);
		t_sample mina_172 = (mul_6927 + mul_6929);
		t_sample min_6914 = ((((int)1) < mina_172) ? ((int)1) : mina_172);
		t_sample rsub_6926 = (((int)1) - min_6914);
		t_sample mul_6925 = (mul_6903 * rsub_6926);
		t_sample sub_6912 = (min_6914 - min_6913);
		t_sample mul_6923 = (m_y_155 * sub_6912);
		t_sample add_6922 = (((mul_6923 + mul_6924) + mul_6925) + ((int)0));
		t_sample mul_6921 = (slide_6915 * add_6922);
		t_sample y2_next_6933 = fixdenorm(m_y_159);
		t_sample history_6917_next_6934 = fixdenorm(switch_6918);
		t_sample history_6906_next_6935 = fixdenorm(switch_6907);
		t_sample history_6932_next_6936 = fixdenorm(switch_6919);
		t_sample y1_next_6937 = fixdenorm(add_6922);
		m_y_155 = y2_next_6933;
		m_y_159 = y1_next_6937;
		m_history_158 = history_6932_next_6936;
		m_history_157 = history_6906_next_6935;
		m_history_156 = history_6917_next_6934;
		return mul_6921;
		
	};
	inline t_sample gen_resonator_d_i_d_d_d_d_i_173(t_sample arg_6938, int arg_6939, t_sample arg_6940, t_sample arg_6941, t_sample arg_6942, t_sample voices, int id) {
		t_sample iup_180 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_181 = (1 / maximum(1, abs(((int)200))));
		__m_slide_179 = fixdenorm((__m_slide_179 + (((m_history_175 > __m_slide_179) ? iup_180 : idown_181) * (m_history_175 - __m_slide_179))));
		t_sample slide_6915 = __m_slide_179;
		int eq_6920 = (id == arg_6939);
		t_sample switch_6918 = (eq_6920 ? arg_6941 : m_history_175);
		t_sample switch_6907 = (eq_6920 ? arg_6942 : m_history_176);
		t_sample switch_6919 = (eq_6920 ? arg_6940 : m_history_177);
		int lt_6910 = (id < voices);
		t_sample iup_183 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_184 = (1 / maximum(1, abs(((int)200))));
		__m_slide_182 = fixdenorm((__m_slide_182 + (((lt_6910 > __m_slide_182) ? iup_183 : idown_184) * (lt_6910 - __m_slide_182))));
		t_sample slide_6904 = __m_slide_182;
		t_sample mul_6903 = (arg_6938 * slide_6904);
		t_sample iup_186 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_187 = (1 / maximum(1, abs(((int)200))));
		__m_slide_185 = fixdenorm((__m_slide_185 + (((m_history_177 > __m_slide_185) ? iup_186 : idown_187) * (m_history_177 - __m_slide_185))));
		t_sample slide_6916 = __m_slide_185;
		t_sample cos_6931 = cos(slide_6916);
		t_sample iup_189 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_190 = (1 / maximum(1, abs(((int)200))));
		__m_slide_188 = fixdenorm((__m_slide_188 + (((m_history_176 > __m_slide_188) ? iup_189 : idown_190) * (m_history_176 - __m_slide_188))));
		t_sample slide_6905 = __m_slide_188;
		t_sample mul_6909 = (slide_6905 * ((int)-1));
		t_sample exp_6928 = exp(mul_6909);
		t_sample mul_6927 = (exp_6928 * ((int)-1));
		t_sample mul_6911 = (slide_6905 * ((t_sample)0.5));
		t_sample exp_6908 = exp(mul_6911);
		t_sample mul_6930 = (cos_6931 * exp_6908);
		t_sample mul_6929 = (mul_6930 * ((int)2));
		t_sample min_6913 = ((((t_sample)1.9999) < mul_6929) ? ((t_sample)1.9999) : mul_6929);
		t_sample mul_6924 = (m_y_178 * min_6913);
		t_sample mina_191 = (mul_6927 + mul_6929);
		t_sample min_6914 = ((((int)1) < mina_191) ? ((int)1) : mina_191);
		t_sample rsub_6926 = (((int)1) - min_6914);
		t_sample mul_6925 = (mul_6903 * rsub_6926);
		t_sample sub_6912 = (min_6914 - min_6913);
		t_sample mul_6923 = (m_y_174 * sub_6912);
		t_sample add_6922 = (((mul_6923 + mul_6924) + mul_6925) + ((int)0));
		t_sample mul_6921 = (slide_6915 * add_6922);
		t_sample y2_next_6933 = fixdenorm(m_y_178);
		t_sample history_6917_next_6934 = fixdenorm(switch_6918);
		t_sample history_6906_next_6935 = fixdenorm(switch_6907);
		t_sample history_6932_next_6936 = fixdenorm(switch_6919);
		t_sample y1_next_6937 = fixdenorm(add_6922);
		m_y_174 = y2_next_6933;
		m_y_178 = y1_next_6937;
		m_history_177 = history_6932_next_6936;
		m_history_176 = history_6906_next_6935;
		m_history_175 = history_6917_next_6934;
		return mul_6921;
		
	};
	inline t_sample gen_resonator_d_i_d_d_d_d_i_192(t_sample arg_6938, int arg_6939, t_sample arg_6940, t_sample arg_6941, t_sample arg_6942, t_sample voices, int id) {
		t_sample iup_199 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_200 = (1 / maximum(1, abs(((int)200))));
		__m_slide_198 = fixdenorm((__m_slide_198 + (((m_history_194 > __m_slide_198) ? iup_199 : idown_200) * (m_history_194 - __m_slide_198))));
		t_sample slide_6915 = __m_slide_198;
		int eq_6920 = (id == arg_6939);
		t_sample switch_6918 = (eq_6920 ? arg_6941 : m_history_194);
		t_sample switch_6907 = (eq_6920 ? arg_6942 : m_history_195);
		t_sample switch_6919 = (eq_6920 ? arg_6940 : m_history_196);
		int lt_6910 = (id < voices);
		t_sample iup_202 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_203 = (1 / maximum(1, abs(((int)200))));
		__m_slide_201 = fixdenorm((__m_slide_201 + (((lt_6910 > __m_slide_201) ? iup_202 : idown_203) * (lt_6910 - __m_slide_201))));
		t_sample slide_6904 = __m_slide_201;
		t_sample mul_6903 = (arg_6938 * slide_6904);
		t_sample iup_205 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_206 = (1 / maximum(1, abs(((int)200))));
		__m_slide_204 = fixdenorm((__m_slide_204 + (((m_history_196 > __m_slide_204) ? iup_205 : idown_206) * (m_history_196 - __m_slide_204))));
		t_sample slide_6916 = __m_slide_204;
		t_sample cos_6931 = cos(slide_6916);
		t_sample iup_208 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_209 = (1 / maximum(1, abs(((int)200))));
		__m_slide_207 = fixdenorm((__m_slide_207 + (((m_history_195 > __m_slide_207) ? iup_208 : idown_209) * (m_history_195 - __m_slide_207))));
		t_sample slide_6905 = __m_slide_207;
		t_sample mul_6909 = (slide_6905 * ((int)-1));
		t_sample exp_6928 = exp(mul_6909);
		t_sample mul_6927 = (exp_6928 * ((int)-1));
		t_sample mul_6911 = (slide_6905 * ((t_sample)0.5));
		t_sample exp_6908 = exp(mul_6911);
		t_sample mul_6930 = (cos_6931 * exp_6908);
		t_sample mul_6929 = (mul_6930 * ((int)2));
		t_sample min_6913 = ((((t_sample)1.9999) < mul_6929) ? ((t_sample)1.9999) : mul_6929);
		t_sample mul_6924 = (m_y_197 * min_6913);
		t_sample mina_210 = (mul_6927 + mul_6929);
		t_sample min_6914 = ((((int)1) < mina_210) ? ((int)1) : mina_210);
		t_sample rsub_6926 = (((int)1) - min_6914);
		t_sample mul_6925 = (mul_6903 * rsub_6926);
		t_sample sub_6912 = (min_6914 - min_6913);
		t_sample mul_6923 = (m_y_193 * sub_6912);
		t_sample add_6922 = (((mul_6923 + mul_6924) + mul_6925) + ((int)0));
		t_sample mul_6921 = (slide_6915 * add_6922);
		t_sample y2_next_6933 = fixdenorm(m_y_197);
		t_sample history_6917_next_6934 = fixdenorm(switch_6918);
		t_sample history_6906_next_6935 = fixdenorm(switch_6907);
		t_sample history_6932_next_6936 = fixdenorm(switch_6919);
		t_sample y1_next_6937 = fixdenorm(add_6922);
		m_y_193 = y2_next_6933;
		m_y_197 = y1_next_6937;
		m_history_196 = history_6932_next_6936;
		m_history_195 = history_6906_next_6935;
		m_history_194 = history_6917_next_6934;
		return mul_6921;
		
	};
	inline t_sample gen_resonator_d_i_d_d_d_d_i_211(t_sample arg_6938, int arg_6939, t_sample arg_6940, t_sample arg_6941, t_sample arg_6942, t_sample voices, int id) {
		t_sample iup_218 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_219 = (1 / maximum(1, abs(((int)200))));
		__m_slide_217 = fixdenorm((__m_slide_217 + (((m_history_213 > __m_slide_217) ? iup_218 : idown_219) * (m_history_213 - __m_slide_217))));
		t_sample slide_6915 = __m_slide_217;
		int eq_6920 = (id == arg_6939);
		t_sample switch_6918 = (eq_6920 ? arg_6941 : m_history_213);
		t_sample switch_6907 = (eq_6920 ? arg_6942 : m_history_214);
		t_sample switch_6919 = (eq_6920 ? arg_6940 : m_history_215);
		int lt_6910 = (id < voices);
		t_sample iup_221 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_222 = (1 / maximum(1, abs(((int)200))));
		__m_slide_220 = fixdenorm((__m_slide_220 + (((lt_6910 > __m_slide_220) ? iup_221 : idown_222) * (lt_6910 - __m_slide_220))));
		t_sample slide_6904 = __m_slide_220;
		t_sample mul_6903 = (arg_6938 * slide_6904);
		t_sample iup_224 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_225 = (1 / maximum(1, abs(((int)200))));
		__m_slide_223 = fixdenorm((__m_slide_223 + (((m_history_215 > __m_slide_223) ? iup_224 : idown_225) * (m_history_215 - __m_slide_223))));
		t_sample slide_6916 = __m_slide_223;
		t_sample cos_6931 = cos(slide_6916);
		t_sample iup_227 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_228 = (1 / maximum(1, abs(((int)200))));
		__m_slide_226 = fixdenorm((__m_slide_226 + (((m_history_214 > __m_slide_226) ? iup_227 : idown_228) * (m_history_214 - __m_slide_226))));
		t_sample slide_6905 = __m_slide_226;
		t_sample mul_6909 = (slide_6905 * ((int)-1));
		t_sample exp_6928 = exp(mul_6909);
		t_sample mul_6927 = (exp_6928 * ((int)-1));
		t_sample mul_6911 = (slide_6905 * ((t_sample)0.5));
		t_sample exp_6908 = exp(mul_6911);
		t_sample mul_6930 = (cos_6931 * exp_6908);
		t_sample mul_6929 = (mul_6930 * ((int)2));
		t_sample min_6913 = ((((t_sample)1.9999) < mul_6929) ? ((t_sample)1.9999) : mul_6929);
		t_sample mul_6924 = (m_y_216 * min_6913);
		t_sample mina_229 = (mul_6927 + mul_6929);
		t_sample min_6914 = ((((int)1) < mina_229) ? ((int)1) : mina_229);
		t_sample rsub_6926 = (((int)1) - min_6914);
		t_sample mul_6925 = (mul_6903 * rsub_6926);
		t_sample sub_6912 = (min_6914 - min_6913);
		t_sample mul_6923 = (m_y_212 * sub_6912);
		t_sample add_6922 = (((mul_6923 + mul_6924) + mul_6925) + ((int)0));
		t_sample mul_6921 = (slide_6915 * add_6922);
		t_sample y2_next_6933 = fixdenorm(m_y_216);
		t_sample history_6917_next_6934 = fixdenorm(switch_6918);
		t_sample history_6906_next_6935 = fixdenorm(switch_6907);
		t_sample history_6932_next_6936 = fixdenorm(switch_6919);
		t_sample y1_next_6937 = fixdenorm(add_6922);
		m_y_212 = y2_next_6933;
		m_y_216 = y1_next_6937;
		m_history_215 = history_6932_next_6936;
		m_history_214 = history_6906_next_6935;
		m_history_213 = history_6917_next_6934;
		return mul_6921;
		
	};
	inline t_sample gen_resonator_d_i_d_d_d_d_i_230(t_sample arg_6938, int arg_6939, t_sample arg_6940, t_sample arg_6941, t_sample arg_6942, t_sample voices, int id) {
		t_sample iup_237 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_238 = (1 / maximum(1, abs(((int)200))));
		__m_slide_236 = fixdenorm((__m_slide_236 + (((m_history_232 > __m_slide_236) ? iup_237 : idown_238) * (m_history_232 - __m_slide_236))));
		t_sample slide_6915 = __m_slide_236;
		int eq_6920 = (id == arg_6939);
		t_sample switch_6918 = (eq_6920 ? arg_6941 : m_history_232);
		t_sample switch_6907 = (eq_6920 ? arg_6942 : m_history_233);
		t_sample switch_6919 = (eq_6920 ? arg_6940 : m_history_234);
		int lt_6910 = (id < voices);
		t_sample iup_240 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_241 = (1 / maximum(1, abs(((int)200))));
		__m_slide_239 = fixdenorm((__m_slide_239 + (((lt_6910 > __m_slide_239) ? iup_240 : idown_241) * (lt_6910 - __m_slide_239))));
		t_sample slide_6904 = __m_slide_239;
		t_sample mul_6903 = (arg_6938 * slide_6904);
		t_sample iup_243 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_244 = (1 / maximum(1, abs(((int)200))));
		__m_slide_242 = fixdenorm((__m_slide_242 + (((m_history_234 > __m_slide_242) ? iup_243 : idown_244) * (m_history_234 - __m_slide_242))));
		t_sample slide_6916 = __m_slide_242;
		t_sample cos_6931 = cos(slide_6916);
		t_sample iup_246 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_247 = (1 / maximum(1, abs(((int)200))));
		__m_slide_245 = fixdenorm((__m_slide_245 + (((m_history_233 > __m_slide_245) ? iup_246 : idown_247) * (m_history_233 - __m_slide_245))));
		t_sample slide_6905 = __m_slide_245;
		t_sample mul_6909 = (slide_6905 * ((int)-1));
		t_sample exp_6928 = exp(mul_6909);
		t_sample mul_6927 = (exp_6928 * ((int)-1));
		t_sample mul_6911 = (slide_6905 * ((t_sample)0.5));
		t_sample exp_6908 = exp(mul_6911);
		t_sample mul_6930 = (cos_6931 * exp_6908);
		t_sample mul_6929 = (mul_6930 * ((int)2));
		t_sample min_6913 = ((((t_sample)1.9999) < mul_6929) ? ((t_sample)1.9999) : mul_6929);
		t_sample mul_6924 = (m_y_235 * min_6913);
		t_sample mina_248 = (mul_6927 + mul_6929);
		t_sample min_6914 = ((((int)1) < mina_248) ? ((int)1) : mina_248);
		t_sample rsub_6926 = (((int)1) - min_6914);
		t_sample mul_6925 = (mul_6903 * rsub_6926);
		t_sample sub_6912 = (min_6914 - min_6913);
		t_sample mul_6923 = (m_y_231 * sub_6912);
		t_sample add_6922 = (((mul_6923 + mul_6924) + mul_6925) + ((int)0));
		t_sample mul_6921 = (slide_6915 * add_6922);
		t_sample y2_next_6933 = fixdenorm(m_y_235);
		t_sample history_6917_next_6934 = fixdenorm(switch_6918);
		t_sample history_6906_next_6935 = fixdenorm(switch_6907);
		t_sample history_6932_next_6936 = fixdenorm(switch_6919);
		t_sample y1_next_6937 = fixdenorm(add_6922);
		m_y_231 = y2_next_6933;
		m_y_235 = y1_next_6937;
		m_history_234 = history_6932_next_6936;
		m_history_233 = history_6906_next_6935;
		m_history_232 = history_6917_next_6934;
		return mul_6921;
		
	};
	inline t_sample gen_resonator_d_i_d_d_d_d_i_249(t_sample arg_6938, int arg_6939, t_sample arg_6940, t_sample arg_6941, t_sample arg_6942, t_sample voices, int id) {
		t_sample iup_256 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_257 = (1 / maximum(1, abs(((int)200))));
		__m_slide_255 = fixdenorm((__m_slide_255 + (((m_history_251 > __m_slide_255) ? iup_256 : idown_257) * (m_history_251 - __m_slide_255))));
		t_sample slide_6915 = __m_slide_255;
		int eq_6920 = (id == arg_6939);
		t_sample switch_6918 = (eq_6920 ? arg_6941 : m_history_251);
		t_sample switch_6907 = (eq_6920 ? arg_6942 : m_history_252);
		t_sample switch_6919 = (eq_6920 ? arg_6940 : m_history_253);
		int lt_6910 = (id < voices);
		t_sample iup_259 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_260 = (1 / maximum(1, abs(((int)200))));
		__m_slide_258 = fixdenorm((__m_slide_258 + (((lt_6910 > __m_slide_258) ? iup_259 : idown_260) * (lt_6910 - __m_slide_258))));
		t_sample slide_6904 = __m_slide_258;
		t_sample mul_6903 = (arg_6938 * slide_6904);
		t_sample iup_262 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_263 = (1 / maximum(1, abs(((int)200))));
		__m_slide_261 = fixdenorm((__m_slide_261 + (((m_history_253 > __m_slide_261) ? iup_262 : idown_263) * (m_history_253 - __m_slide_261))));
		t_sample slide_6916 = __m_slide_261;
		t_sample cos_6931 = cos(slide_6916);
		t_sample iup_265 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_266 = (1 / maximum(1, abs(((int)200))));
		__m_slide_264 = fixdenorm((__m_slide_264 + (((m_history_252 > __m_slide_264) ? iup_265 : idown_266) * (m_history_252 - __m_slide_264))));
		t_sample slide_6905 = __m_slide_264;
		t_sample mul_6909 = (slide_6905 * ((int)-1));
		t_sample exp_6928 = exp(mul_6909);
		t_sample mul_6927 = (exp_6928 * ((int)-1));
		t_sample mul_6911 = (slide_6905 * ((t_sample)0.5));
		t_sample exp_6908 = exp(mul_6911);
		t_sample mul_6930 = (cos_6931 * exp_6908);
		t_sample mul_6929 = (mul_6930 * ((int)2));
		t_sample min_6913 = ((((t_sample)1.9999) < mul_6929) ? ((t_sample)1.9999) : mul_6929);
		t_sample mul_6924 = (m_y_254 * min_6913);
		t_sample mina_267 = (mul_6927 + mul_6929);
		t_sample min_6914 = ((((int)1) < mina_267) ? ((int)1) : mina_267);
		t_sample rsub_6926 = (((int)1) - min_6914);
		t_sample mul_6925 = (mul_6903 * rsub_6926);
		t_sample sub_6912 = (min_6914 - min_6913);
		t_sample mul_6923 = (m_y_250 * sub_6912);
		t_sample add_6922 = (((mul_6923 + mul_6924) + mul_6925) + ((int)0));
		t_sample mul_6921 = (slide_6915 * add_6922);
		t_sample y2_next_6933 = fixdenorm(m_y_254);
		t_sample history_6917_next_6934 = fixdenorm(switch_6918);
		t_sample history_6906_next_6935 = fixdenorm(switch_6907);
		t_sample history_6932_next_6936 = fixdenorm(switch_6919);
		t_sample y1_next_6937 = fixdenorm(add_6922);
		m_y_250 = y2_next_6933;
		m_y_254 = y1_next_6937;
		m_history_253 = history_6932_next_6936;
		m_history_252 = history_6906_next_6935;
		m_history_251 = history_6917_next_6934;
		return mul_6921;
		
	};
	inline t_sample gen_resonator_d_i_d_d_d_d_i_268(t_sample arg_6938, int arg_6939, t_sample arg_6940, t_sample arg_6941, t_sample arg_6942, t_sample voices, int id) {
		t_sample iup_275 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_276 = (1 / maximum(1, abs(((int)200))));
		__m_slide_274 = fixdenorm((__m_slide_274 + (((m_history_270 > __m_slide_274) ? iup_275 : idown_276) * (m_history_270 - __m_slide_274))));
		t_sample slide_6915 = __m_slide_274;
		int eq_6920 = (id == arg_6939);
		t_sample switch_6918 = (eq_6920 ? arg_6941 : m_history_270);
		t_sample switch_6907 = (eq_6920 ? arg_6942 : m_history_271);
		t_sample switch_6919 = (eq_6920 ? arg_6940 : m_history_272);
		int lt_6910 = (id < voices);
		t_sample iup_278 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_279 = (1 / maximum(1, abs(((int)200))));
		__m_slide_277 = fixdenorm((__m_slide_277 + (((lt_6910 > __m_slide_277) ? iup_278 : idown_279) * (lt_6910 - __m_slide_277))));
		t_sample slide_6904 = __m_slide_277;
		t_sample mul_6903 = (arg_6938 * slide_6904);
		t_sample iup_281 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_282 = (1 / maximum(1, abs(((int)200))));
		__m_slide_280 = fixdenorm((__m_slide_280 + (((m_history_272 > __m_slide_280) ? iup_281 : idown_282) * (m_history_272 - __m_slide_280))));
		t_sample slide_6916 = __m_slide_280;
		t_sample cos_6931 = cos(slide_6916);
		t_sample iup_284 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_285 = (1 / maximum(1, abs(((int)200))));
		__m_slide_283 = fixdenorm((__m_slide_283 + (((m_history_271 > __m_slide_283) ? iup_284 : idown_285) * (m_history_271 - __m_slide_283))));
		t_sample slide_6905 = __m_slide_283;
		t_sample mul_6909 = (slide_6905 * ((int)-1));
		t_sample exp_6928 = exp(mul_6909);
		t_sample mul_6927 = (exp_6928 * ((int)-1));
		t_sample mul_6911 = (slide_6905 * ((t_sample)0.5));
		t_sample exp_6908 = exp(mul_6911);
		t_sample mul_6930 = (cos_6931 * exp_6908);
		t_sample mul_6929 = (mul_6930 * ((int)2));
		t_sample min_6913 = ((((t_sample)1.9999) < mul_6929) ? ((t_sample)1.9999) : mul_6929);
		t_sample mul_6924 = (m_y_273 * min_6913);
		t_sample mina_286 = (mul_6927 + mul_6929);
		t_sample min_6914 = ((((int)1) < mina_286) ? ((int)1) : mina_286);
		t_sample rsub_6926 = (((int)1) - min_6914);
		t_sample mul_6925 = (mul_6903 * rsub_6926);
		t_sample sub_6912 = (min_6914 - min_6913);
		t_sample mul_6923 = (m_y_269 * sub_6912);
		t_sample add_6922 = (((mul_6923 + mul_6924) + mul_6925) + ((int)0));
		t_sample mul_6921 = (slide_6915 * add_6922);
		t_sample y2_next_6933 = fixdenorm(m_y_273);
		t_sample history_6917_next_6934 = fixdenorm(switch_6918);
		t_sample history_6906_next_6935 = fixdenorm(switch_6907);
		t_sample history_6932_next_6936 = fixdenorm(switch_6919);
		t_sample y1_next_6937 = fixdenorm(add_6922);
		m_y_269 = y2_next_6933;
		m_y_273 = y1_next_6937;
		m_history_272 = history_6932_next_6936;
		m_history_271 = history_6906_next_6935;
		m_history_270 = history_6917_next_6934;
		return mul_6921;
		
	};
	inline t_sample gen_resonator_d_i_d_d_d_d_i_287(t_sample arg_6938, int arg_6939, t_sample arg_6940, t_sample arg_6941, t_sample arg_6942, t_sample voices, int id) {
		t_sample iup_294 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_295 = (1 / maximum(1, abs(((int)200))));
		__m_slide_293 = fixdenorm((__m_slide_293 + (((m_history_289 > __m_slide_293) ? iup_294 : idown_295) * (m_history_289 - __m_slide_293))));
		t_sample slide_6915 = __m_slide_293;
		int eq_6920 = (id == arg_6939);
		t_sample switch_6918 = (eq_6920 ? arg_6941 : m_history_289);
		t_sample switch_6907 = (eq_6920 ? arg_6942 : m_history_290);
		t_sample switch_6919 = (eq_6920 ? arg_6940 : m_history_291);
		int lt_6910 = (id < voices);
		t_sample iup_297 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_298 = (1 / maximum(1, abs(((int)200))));
		__m_slide_296 = fixdenorm((__m_slide_296 + (((lt_6910 > __m_slide_296) ? iup_297 : idown_298) * (lt_6910 - __m_slide_296))));
		t_sample slide_6904 = __m_slide_296;
		t_sample mul_6903 = (arg_6938 * slide_6904);
		t_sample iup_300 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_301 = (1 / maximum(1, abs(((int)200))));
		__m_slide_299 = fixdenorm((__m_slide_299 + (((m_history_291 > __m_slide_299) ? iup_300 : idown_301) * (m_history_291 - __m_slide_299))));
		t_sample slide_6916 = __m_slide_299;
		t_sample cos_6931 = cos(slide_6916);
		t_sample iup_303 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_304 = (1 / maximum(1, abs(((int)200))));
		__m_slide_302 = fixdenorm((__m_slide_302 + (((m_history_290 > __m_slide_302) ? iup_303 : idown_304) * (m_history_290 - __m_slide_302))));
		t_sample slide_6905 = __m_slide_302;
		t_sample mul_6909 = (slide_6905 * ((int)-1));
		t_sample exp_6928 = exp(mul_6909);
		t_sample mul_6927 = (exp_6928 * ((int)-1));
		t_sample mul_6911 = (slide_6905 * ((t_sample)0.5));
		t_sample exp_6908 = exp(mul_6911);
		t_sample mul_6930 = (cos_6931 * exp_6908);
		t_sample mul_6929 = (mul_6930 * ((int)2));
		t_sample min_6913 = ((((t_sample)1.9999) < mul_6929) ? ((t_sample)1.9999) : mul_6929);
		t_sample mul_6924 = (m_y_292 * min_6913);
		t_sample mina_305 = (mul_6927 + mul_6929);
		t_sample min_6914 = ((((int)1) < mina_305) ? ((int)1) : mina_305);
		t_sample rsub_6926 = (((int)1) - min_6914);
		t_sample mul_6925 = (mul_6903 * rsub_6926);
		t_sample sub_6912 = (min_6914 - min_6913);
		t_sample mul_6923 = (m_y_288 * sub_6912);
		t_sample add_6922 = (((mul_6923 + mul_6924) + mul_6925) + ((int)0));
		t_sample mul_6921 = (slide_6915 * add_6922);
		t_sample y2_next_6933 = fixdenorm(m_y_292);
		t_sample history_6917_next_6934 = fixdenorm(switch_6918);
		t_sample history_6906_next_6935 = fixdenorm(switch_6907);
		t_sample history_6932_next_6936 = fixdenorm(switch_6919);
		t_sample y1_next_6937 = fixdenorm(add_6922);
		m_y_288 = y2_next_6933;
		m_y_292 = y1_next_6937;
		m_history_291 = history_6932_next_6936;
		m_history_290 = history_6906_next_6935;
		m_history_289 = history_6917_next_6934;
		return mul_6921;
		
	};
	inline t_sample gen_resonator_d_i_d_d_d_d_i_306(t_sample arg_6938, int arg_6939, t_sample arg_6940, t_sample arg_6941, t_sample arg_6942, t_sample voices, int id) {
		t_sample iup_313 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_314 = (1 / maximum(1, abs(((int)200))));
		__m_slide_312 = fixdenorm((__m_slide_312 + (((m_history_308 > __m_slide_312) ? iup_313 : idown_314) * (m_history_308 - __m_slide_312))));
		t_sample slide_6915 = __m_slide_312;
		int eq_6920 = (id == arg_6939);
		t_sample switch_6918 = (eq_6920 ? arg_6941 : m_history_308);
		t_sample switch_6907 = (eq_6920 ? arg_6942 : m_history_309);
		t_sample switch_6919 = (eq_6920 ? arg_6940 : m_history_310);
		int lt_6910 = (id < voices);
		t_sample iup_316 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_317 = (1 / maximum(1, abs(((int)200))));
		__m_slide_315 = fixdenorm((__m_slide_315 + (((lt_6910 > __m_slide_315) ? iup_316 : idown_317) * (lt_6910 - __m_slide_315))));
		t_sample slide_6904 = __m_slide_315;
		t_sample mul_6903 = (arg_6938 * slide_6904);
		t_sample iup_319 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_320 = (1 / maximum(1, abs(((int)200))));
		__m_slide_318 = fixdenorm((__m_slide_318 + (((m_history_310 > __m_slide_318) ? iup_319 : idown_320) * (m_history_310 - __m_slide_318))));
		t_sample slide_6916 = __m_slide_318;
		t_sample cos_6931 = cos(slide_6916);
		t_sample iup_322 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_323 = (1 / maximum(1, abs(((int)200))));
		__m_slide_321 = fixdenorm((__m_slide_321 + (((m_history_309 > __m_slide_321) ? iup_322 : idown_323) * (m_history_309 - __m_slide_321))));
		t_sample slide_6905 = __m_slide_321;
		t_sample mul_6909 = (slide_6905 * ((int)-1));
		t_sample exp_6928 = exp(mul_6909);
		t_sample mul_6927 = (exp_6928 * ((int)-1));
		t_sample mul_6911 = (slide_6905 * ((t_sample)0.5));
		t_sample exp_6908 = exp(mul_6911);
		t_sample mul_6930 = (cos_6931 * exp_6908);
		t_sample mul_6929 = (mul_6930 * ((int)2));
		t_sample min_6913 = ((((t_sample)1.9999) < mul_6929) ? ((t_sample)1.9999) : mul_6929);
		t_sample mul_6924 = (m_y_311 * min_6913);
		t_sample mina_324 = (mul_6927 + mul_6929);
		t_sample min_6914 = ((((int)1) < mina_324) ? ((int)1) : mina_324);
		t_sample rsub_6926 = (((int)1) - min_6914);
		t_sample mul_6925 = (mul_6903 * rsub_6926);
		t_sample sub_6912 = (min_6914 - min_6913);
		t_sample mul_6923 = (m_y_307 * sub_6912);
		t_sample add_6922 = (((mul_6923 + mul_6924) + mul_6925) + ((int)0));
		t_sample mul_6921 = (slide_6915 * add_6922);
		t_sample y2_next_6933 = fixdenorm(m_y_311);
		t_sample history_6917_next_6934 = fixdenorm(switch_6918);
		t_sample history_6906_next_6935 = fixdenorm(switch_6907);
		t_sample history_6932_next_6936 = fixdenorm(switch_6919);
		t_sample y1_next_6937 = fixdenorm(add_6922);
		m_y_307 = y2_next_6933;
		m_y_311 = y1_next_6937;
		m_history_310 = history_6932_next_6936;
		m_history_309 = history_6906_next_6935;
		m_history_308 = history_6917_next_6934;
		return mul_6921;
		
	};
	inline t_sample gen_resonator_d_i_d_d_d_d_i_325(t_sample arg_6938, int arg_6939, t_sample arg_6940, t_sample arg_6941, t_sample arg_6942, t_sample voices, int id) {
		t_sample iup_332 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_333 = (1 / maximum(1, abs(((int)200))));
		__m_slide_331 = fixdenorm((__m_slide_331 + (((m_history_327 > __m_slide_331) ? iup_332 : idown_333) * (m_history_327 - __m_slide_331))));
		t_sample slide_6915 = __m_slide_331;
		int eq_6920 = (id == arg_6939);
		t_sample switch_6918 = (eq_6920 ? arg_6941 : m_history_327);
		t_sample switch_6907 = (eq_6920 ? arg_6942 : m_history_328);
		t_sample switch_6919 = (eq_6920 ? arg_6940 : m_history_329);
		int lt_6910 = (id < voices);
		t_sample iup_335 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_336 = (1 / maximum(1, abs(((int)200))));
		__m_slide_334 = fixdenorm((__m_slide_334 + (((lt_6910 > __m_slide_334) ? iup_335 : idown_336) * (lt_6910 - __m_slide_334))));
		t_sample slide_6904 = __m_slide_334;
		t_sample mul_6903 = (arg_6938 * slide_6904);
		t_sample iup_338 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_339 = (1 / maximum(1, abs(((int)200))));
		__m_slide_337 = fixdenorm((__m_slide_337 + (((m_history_329 > __m_slide_337) ? iup_338 : idown_339) * (m_history_329 - __m_slide_337))));
		t_sample slide_6916 = __m_slide_337;
		t_sample cos_6931 = cos(slide_6916);
		t_sample iup_341 = (1 / maximum(1, abs(((int)200))));
		t_sample idown_342 = (1 / maximum(1, abs(((int)200))));
		__m_slide_340 = fixdenorm((__m_slide_340 + (((m_history_328 > __m_slide_340) ? iup_341 : idown_342) * (m_history_328 - __m_slide_340))));
		t_sample slide_6905 = __m_slide_340;
		t_sample mul_6909 = (slide_6905 * ((int)-1));
		t_sample exp_6928 = exp(mul_6909);
		t_sample mul_6927 = (exp_6928 * ((int)-1));
		t_sample mul_6911 = (slide_6905 * ((t_sample)0.5));
		t_sample exp_6908 = exp(mul_6911);
		t_sample mul_6930 = (cos_6931 * exp_6908);
		t_sample mul_6929 = (mul_6930 * ((int)2));
		t_sample min_6913 = ((((t_sample)1.9999) < mul_6929) ? ((t_sample)1.9999) : mul_6929);
		t_sample mul_6924 = (m_y_330 * min_6913);
		t_sample mina_343 = (mul_6927 + mul_6929);
		t_sample min_6914 = ((((int)1) < mina_343) ? ((int)1) : mina_343);
		t_sample rsub_6926 = (((int)1) - min_6914);
		t_sample mul_6925 = (mul_6903 * rsub_6926);
		t_sample sub_6912 = (min_6914 - min_6913);
		t_sample mul_6923 = (m_y_326 * sub_6912);
		t_sample add_6922 = (((mul_6923 + mul_6924) + mul_6925) + ((int)0));
		t_sample mul_6921 = (slide_6915 * add_6922);
		t_sample y2_next_6933 = fixdenorm(m_y_330);
		t_sample history_6917_next_6934 = fixdenorm(switch_6918);
		t_sample history_6906_next_6935 = fixdenorm(switch_6907);
		t_sample history_6932_next_6936 = fixdenorm(switch_6919);
		t_sample y1_next_6937 = fixdenorm(add_6922);
		m_y_326 = y2_next_6933;
		m_y_330 = y1_next_6937;
		m_history_329 = history_6932_next_6936;
		m_history_328 = history_6906_next_6935;
		m_history_327 = history_6917_next_6934;
		return mul_6921;
		
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 3;
int gen_kernel_numouts = 12;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 21; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2", "in3" };
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
		case 0: self->set_N(value); break;
		case 1: self->set_cvin1(value); break;
		case 2: self->set_gate1(value); break;
		case 3: self->set_history_6077(value); break;
		case 4: self->set_history_6104(value); break;
		case 5: self->set_knob1(value); break;
		case 6: self->set_knob2(value); break;
		case 7: self->set_knob3(value); break;
		case 8: self->set_knob4_voices(value); break;
		case 9: self->set_knob5(value); break;
		case 10: self->set_knob6(value); break;
		case 11: self->set_params(ref); break;
		case 12: self->set_sw1(value); break;
		case 13: self->set_sw2(value); break;
		case 14: self->set_sw3(value); break;
		case 15: self->set_sw4(value); break;
		case 16: self->set_sw5(value); break;
		case 17: self->set_sw6(value); break;
		case 18: self->set_sw7(value); break;
		case 19: self->set_sw8(value); break;
		case 20: self->set_terrain(ref); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_N_1; break;
		case 1: *value = self->m_cvin_25; break;
		case 2: *value = self->m_gate_12; break;
		case 3: *value = self->m_history_2; break;
		case 4: *value = self->m_history_3; break;
		case 5: *value = self->m_knob_24; break;
		case 6: *value = self->m_knob_23; break;
		case 7: *value = self->m_knob_21; break;
		case 8: *value = self->m_knob4_voices_18; break;
		case 9: *value = self->m_knob_20; break;
		case 10: *value = self->m_knob_19; break;
		
		case 12: *value = self->m_sw_28; break;
		case 13: *value = self->m_sw_17; break;
		case 14: *value = self->m_sw_14; break;
		case 15: *value = self->m_sw_26; break;
		case 16: *value = self->m_sw_13; break;
		case 17: *value = self->m_sw_16; break;
		case 18: *value = self->m_sw_29; break;
		case 19: *value = self->m_sw_15; break;
		
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(21 * sizeof(ParamInfo));
	self->__commonstate.numparams = 21;
	// initialize parameter 0 ("m_N_1")
	pi = self->__commonstate.params + 0;
	pi->name = "N";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_N_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_cvin_25")
	pi = self->__commonstate.params + 1;
	pi->name = "cvin1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cvin_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_gate_12")
	pi = self->__commonstate.params + 2;
	pi->name = "gate1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_12;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_history_2")
	pi = self->__commonstate.params + 3;
	pi->name = "history_6077";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_history_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_history_3")
	pi = self->__commonstate.params + 4;
	pi->name = "history_6104";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_history_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_knob_24")
	pi = self->__commonstate.params + 5;
	pi->name = "knob1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_knob_23")
	pi = self->__commonstate.params + 6;
	pi->name = "knob2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_knob_21")
	pi = self->__commonstate.params + 7;
	pi->name = "knob3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_knob4_voices_18")
	pi = self->__commonstate.params + 8;
	pi->name = "knob4_voices";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_voices_18;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 16;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_knob_20")
	pi = self->__commonstate.params + 9;
	pi->name = "knob5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_knob_19")
	pi = self->__commonstate.params + 10;
	pi->name = "knob6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_params_22")
	pi = self->__commonstate.params + 11;
	pi->name = "params";
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
	// initialize parameter 12 ("m_sw_28")
	pi = self->__commonstate.params + 12;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_sw_17")
	pi = self->__commonstate.params + 13;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_sw_14")
	pi = self->__commonstate.params + 14;
	pi->name = "sw3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_14;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_sw_26")
	pi = self->__commonstate.params + 15;
	pi->name = "sw4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 16 ("m_sw_13")
	pi = self->__commonstate.params + 16;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_13;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 17 ("m_sw_16")
	pi = self->__commonstate.params + 17;
	pi->name = "sw6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_16;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 18 ("m_sw_29")
	pi = self->__commonstate.params + 18;
	pi->name = "sw7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_29;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 19 ("m_sw_15")
	pi = self->__commonstate.params + 19;
	pi->name = "sw8";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_15;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 20 ("m_terrain_27")
	pi = self->__commonstate.params + 20;
	pi->name = "terrain";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = genlib_obtain_reference_from_string("terrain");
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
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
