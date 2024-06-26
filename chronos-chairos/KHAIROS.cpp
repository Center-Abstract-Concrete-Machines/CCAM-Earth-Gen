#include "KHAIROS.h"

namespace KHAIROS {

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
	Change __m_change_93;
	Change __m_change_131;
	Change __m_change_61;
	Change __m_change_60;
	Change __m_change_92;
	Change __m_change_62;
	Change __m_change_64;
	Change __m_change_63;
	Change __m_change_65;
	Change __m_change_127;
	Change __m_change_59;
	Change __m_change_140;
	Change __m_change_66;
	Change __m_change_150;
	Change __m_change_155;
	Change __m_change_145;
	Data m_snare_patterns_37;
	Data m_hihat_hit_values_36;
	Data m_snare_array_45;
	Data m_noise_array_27;
	Data m_snare_hit_values_34;
	Data m_hihat_patterns_33;
	Data m_grid_matrix_noise_48;
	Data m_kick_array_40;
	Data m_hihat_array_42;
	Delta __m_delta_91;
	Delta __m_delta_149;
	Delta __m_delta_154;
	Delta __m_delta_139;
	Delta __m_delta_144;
	Delta __m_delta_130;
	Phasor __m_phasor_138;
	Phasor __m_phasor_137;
	Phasor __m_phasor_129;
	PlusEquals __m_pluseq_146;
	PlusEquals __m_pluseq_156;
	PlusEquals __m_pluseq_157;
	PlusEquals __m_pluseq_158;
	PlusEquals __m_pluseq_128;
	PlusEquals __m_pluseq_159;
	PlusEquals __m_pluseq_151;
	int __loopcount;
	int __exception;
	int vectorsize;
	t_sample __m_count_132;
	t_sample m_knob3_Y_41;
	t_sample __m_carry_134;
	t_sample m_hit_2_hihat_12;
	t_sample m_hit_3_hihat_11;
	t_sample m_hit_1_hihat_13;
	t_sample m_hit_4_hihat_10;
	t_sample m_hit_8_snare_14;
	t_sample samples_to_seconds;
	t_sample __m_latch_126;
	t_sample m_hit_7_snare_15;
	t_sample m_hit_5_snare_17;
	t_sample m_hit_6_snare_16;
	t_sample m_hit_5_hihat_9;
	t_sample __m_count_141;
	t_sample __m_latch_143;
	t_sample __m_latch_153;
	t_sample m_history_3;
	t_sample m_history_2;
	t_sample samplerate;
	t_sample m_history_1;
	t_sample m_hit_4_snare_18;
	t_sample m_history_4;
	t_sample __m_latch_148;
	t_sample m_hit_6_hihat_8;
	t_sample m_history_5;
	t_sample m_hit_7_hihat_7;
	t_sample m_hit_8_hihat_6;
	t_sample m_mix_39;
	t_sample m_hit_3_snare_19;
	t_sample m_hit_1_snare_21;
	t_sample m_sw_31;
	t_sample m_sw_32;
	t_sample m_sw_50;
	t_sample m_led_52;
	t_sample m_led_51;
	t_sample m_led_53;
	t_sample m_knob4_swing_47;
	t_sample m_sw_35;
	t_sample m_knob5_snareDensity_38;
	t_sample m_knob1_bpm_46;
	t_sample m_knob2_X_43;
	t_sample m_knob6_hihatDensity_44;
	t_sample m_hit_2_snare_20;
	t_sample m_led_54;
	t_sample m_led_56;
	t_sample m_z_24;
	t_sample m_x_25;
	t_sample m_history_23;
	t_sample elapsed;
	t_sample m_history_22;
	t_sample m_led_55;
	t_sample m_y_26;
	t_sample m_sw_29;
	t_sample m_led_57;
	t_sample m_sw_28;
	t_sample m_led_58;
	t_sample m_sw_30;
	t_sample m_sw_49;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_history_4 = ((int)0);
		m_history_5 = ((int)0);
		m_hit_8_hihat_6 = ((int)0);
		m_hit_7_hihat_7 = ((int)0);
		m_hit_6_hihat_8 = ((int)0);
		m_hit_5_hihat_9 = ((int)0);
		m_hit_4_hihat_10 = ((int)0);
		m_hit_3_hihat_11 = ((int)0);
		m_hit_2_hihat_12 = ((int)0);
		m_hit_1_hihat_13 = ((int)0);
		m_hit_8_snare_14 = ((int)0);
		m_hit_7_snare_15 = ((int)0);
		m_hit_6_snare_16 = ((int)0);
		m_hit_5_snare_17 = ((int)0);
		m_hit_4_snare_18 = ((int)0);
		m_hit_3_snare_19 = ((int)0);
		m_hit_2_snare_20 = ((int)0);
		m_hit_1_snare_21 = ((int)0);
		m_history_22 = ((int)0);
		m_history_23 = ((int)0);
		m_z_24 = ((int)0);
		m_x_25 = ((int)0);
		m_y_26 = ((int)0);
		m_noise_array_27.reset("noise_array", ((int)48000), ((int)1));
		m_sw_28 = ((int)0);
		m_sw_29 = ((int)0);
		m_sw_30 = ((int)0);
		m_sw_31 = ((int)0);
		m_sw_32 = ((int)0);
		m_hihat_patterns_33.reset("hihat_patterns", ((int)8), ((int)64));
		m_snare_hit_values_34.reset("snare_hit_values", ((int)8), ((int)64));
		m_sw_35 = ((int)0);
		m_hihat_hit_values_36.reset("hihat_hit_values", ((int)8), ((int)64));
		m_snare_patterns_37.reset("snare_patterns", ((int)8), ((int)64));
		m_knob5_snareDensity_38 = ((int)1);
		m_mix_39 = ((t_sample)0.5);
		m_kick_array_40.reset("kick_array", ((int)8), ((int)1));
		m_knob3_Y_41 = ((int)0);
		m_hihat_array_42.reset("hihat_array", ((int)8), ((int)2));
		m_knob2_X_43 = ((int)0);
		m_knob6_hihatDensity_44 = ((int)1);
		m_snare_array_45.reset("snare_array", ((int)8), ((int)2));
		m_knob1_bpm_46 = ((int)0);
		m_knob4_swing_47 = ((int)0);
		m_grid_matrix_noise_48.reset("grid_matrix_noise", ((int)64), ((int)1));
		m_sw_49 = ((int)0);
		m_sw_50 = ((int)0);
		m_led_51 = ((int)0);
		m_led_52 = ((int)0);
		m_led_53 = ((int)0);
		m_led_54 = ((int)0);
		m_led_55 = ((int)0);
		m_led_56 = ((int)0);
		m_led_57 = ((int)0);
		m_led_58 = ((int)0);
		__m_change_59.reset(0);
		__m_change_60.reset(0);
		__m_change_61.reset(0);
		__m_change_62.reset(0);
		__m_change_63.reset(0);
		__m_change_64.reset(0);
		__m_change_65.reset(0);
		__m_change_66.reset(0);
		elapsed = 0;
		__m_delta_91.reset(0);
		__m_change_92.reset(0);
		__m_change_93.reset(0);
		__m_latch_126 = 0;
		__m_change_127.reset(0);
		__m_pluseq_128.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_129.reset(0);
		__m_delta_130.reset(0);
		__m_change_131.reset(0);
		__m_count_132 = 0;
		__m_carry_134 = 0;
		__m_phasor_137.reset(0);
		__m_phasor_138.reset(0);
		__m_delta_139.reset(0);
		__m_change_140.reset(0);
		__m_count_141 = 0;
		__m_latch_143 = 0;
		__m_delta_144.reset(0);
		__m_change_145.reset(0);
		__m_pluseq_146.reset(0);
		__m_latch_148 = 0;
		__m_delta_149.reset(0);
		__m_change_150.reset(0);
		__m_pluseq_151.reset(0);
		__m_latch_153 = 0;
		__m_delta_154.reset(0);
		__m_change_155.reset(0);
		__m_pluseq_156.reset(0);
		__m_pluseq_157.reset(0);
		__m_pluseq_158.reset(0);
		__m_pluseq_159.reset(0);
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
		t_sample * __out13 = __outs[12];
		t_sample * __out14 = __outs[13];
		t_sample * __out15 = __outs[14];
		t_sample * __out16 = __outs[15];
		t_sample * __out17 = __outs[16];
		t_sample * __out18 = __outs[17];
		t_sample * __out19 = __outs[18];
		t_sample * __out20 = __outs[19];
		t_sample * __out21 = __outs[20];
		t_sample * __out22 = __outs[21];
		t_sample * __out23 = __outs[22];
		t_sample * __out24 = __outs[23];
		t_sample * __out25 = __outs[24];
		t_sample * __out26 = __outs[25];
		t_sample * __out27 = __outs[26];
		t_sample * __out28 = __outs[27];
		t_sample * __out29 = __outs[28];
		t_sample * __out30 = __outs[29];
		t_sample * __out31 = __outs[30];
		t_sample * __out32 = __outs[31];
		t_sample * __out33 = __outs[32];
		t_sample * __out34 = __outs[33];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) || (__out7 == 0) || (__out8 == 0) || (__out9 == 0) || (__out10 == 0) || (__out11 == 0) || (__out12 == 0) || (__out13 == 0) || (__out14 == 0) || (__out15 == 0) || (__out16 == 0) || (__out17 == 0) || (__out18 == 0) || (__out19 == 0) || (__out20 == 0) || (__out21 == 0) || (__out22 == 0) || (__out23 == 0) || (__out24 == 0) || (__out25 == 0) || (__out26 == 0) || (__out27 == 0) || (__out28 == 0) || (__out29 == 0) || (__out30 == 0) || (__out31 == 0) || (__out32 == 0) || (__out33 == 0) || (__out34 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		__loopcount = (__n * GENLIB_LOOPCOUNT_BAIL);
		t_sample sub_22122 = (m_knob2_X_43 - ((int)0));
		t_sample scale_22119 = ((safepow((sub_22122 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)1));
		t_sample expr_21771 = round(scale_22119);
		t_sample sub_22126 = (m_knob3_Y_41 - ((int)0));
		t_sample scale_22123 = ((safepow((sub_22126 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)1));
		t_sample expr_21772 = round(scale_22123);
		int iftrue_90 = (-10000000000);
		t_sample mstosamps_18977 = (((int)1) * (samplerate * 0.001));
		t_sample max_18978 = ((mstosamps_18977 < vectorsize) ? vectorsize : mstosamps_18977);
		t_sample sub_22143 = (m_knob1_bpm_46 - ((int)0));
		t_sample scale_22140 = ((safepow((sub_22143 * ((t_sample)1)), ((int)1)) * ((int)-460)) + ((int)500));
		t_sample scale_19068 = scale_22140;
		t_sample div_19169 = (scale_19068 * ((t_sample)0.016666666666667));
		t_sample div_19030 = (div_19169 * ((t_sample)0.125));
		t_sample div_18922 = safediv(div_19030, samplerate);
		samples_to_seconds = (1 / samplerate);
		int grid_matrix_noise_dim = m_grid_matrix_noise_48.dim;
		int grid_matrix_noise_channels = m_grid_matrix_noise_48.channels;
		int kick_array_dim = m_kick_array_40.dim;
		int kick_array_channels = m_kick_array_40.channels;
		int hihat_array_dim = m_hihat_array_42.dim;
		int hihat_array_channels = m_hihat_array_42.channels;
		int snare_array_dim = m_snare_array_45.dim;
		int snare_array_channels = m_snare_array_45.channels;
		int min_161 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			int sw_1 = (__m_change_59((m_sw_31 > ((int)0))) > ((int)0));
			int sw_2 = (__m_change_60((m_sw_49 > ((int)0))) > ((int)0));
			int sw_3 = (__m_change_61((m_sw_30 > ((int)0))) > ((int)0));
			int sw_4 = (__m_change_62((m_sw_32 > ((int)0))) > ((int)0));
			int sw_5 = (__m_change_63((m_sw_29 > ((int)0))) > ((int)0));
			int sw_6 = (__m_change_64((m_sw_50 > ((int)0))) > ((int)0));
			int sw_7 = (__m_change_65((m_sw_35 > ((int)0))) > ((int)0));
			int sw_8 = (__m_change_66((m_sw_28 > ((int)0))) > ((int)0));
			if ((elapsed == ((int)0))) {
				// for loop initializer;
				int i = ((int)0);
				// for loop condition;
				int kick_array_dim = m_kick_array_40.dim;
				int kick_array_channels = m_kick_array_40.channels;
				while ((i < kick_array_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					bool index_ignore_67 = ((i >= kick_array_dim) || (i < 0));
					if ((!index_ignore_67)) {
						m_kick_array_40.write(((int)0), i, 0);
						
					};
					// for loop increment;
					i = (i + ((int)1));
					
				};
				m_led_58 = ((int)1);
				m_led_57 = ((int)1);
				m_led_56 = ((int)1);
				m_led_55 = ((int)1);
				m_led_54 = ((int)1);
				m_led_53 = ((int)1);
				m_led_52 = ((int)1);
				m_led_51 = ((int)1);
				
			};
			// abort processing if an infinite loop is suspected;
			if (((__loopcount--) <= 0)) {
				__exception = GENLIB_ERR_LOOP_OVERFLOW;
				break ;
				
			};
			if (sw_1) {
				int kick_array_dim = m_kick_array_40.dim;
				int kick_array_channels = m_kick_array_40.channels;
				// samples kick_array channel 1;
				t_sample a = m_kick_array_40.read(0, 0);
				m_kick_array_40.write((!a), 0, 0);
				m_led_58 = a;
				
			};
			if (sw_2) {
				int kick_array_dim = m_kick_array_40.dim;
				int kick_array_channels = m_kick_array_40.channels;
				bool index_ignore_68 = (((int)1) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_68 ? 0 : m_kick_array_40.read(((int)1), 0));
				bool index_ignore_69 = (((int)1) >= kick_array_dim);
				if ((!index_ignore_69)) {
					m_kick_array_40.write((!a), ((int)1), 0);
					
				};
				m_led_57 = a;
				
			};
			if (sw_3) {
				int kick_array_dim = m_kick_array_40.dim;
				int kick_array_channels = m_kick_array_40.channels;
				bool index_ignore_70 = (((int)2) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_70 ? 0 : m_kick_array_40.read(((int)2), 0));
				bool index_ignore_71 = (((int)2) >= kick_array_dim);
				if ((!index_ignore_71)) {
					m_kick_array_40.write((!a), ((int)2), 0);
					
				};
				m_led_56 = a;
				
			};
			if (sw_4) {
				int kick_array_dim = m_kick_array_40.dim;
				int kick_array_channels = m_kick_array_40.channels;
				bool index_ignore_72 = (((int)3) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_72 ? 0 : m_kick_array_40.read(((int)3), 0));
				bool index_ignore_73 = (((int)3) >= kick_array_dim);
				if ((!index_ignore_73)) {
					m_kick_array_40.write((!a), ((int)3), 0);
					
				};
				m_led_55 = a;
				
			};
			if (sw_5) {
				int kick_array_dim = m_kick_array_40.dim;
				int kick_array_channels = m_kick_array_40.channels;
				bool index_ignore_74 = (((int)4) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_74 ? 0 : m_kick_array_40.read(((int)4), 0));
				bool index_ignore_75 = (((int)4) >= kick_array_dim);
				if ((!index_ignore_75)) {
					m_kick_array_40.write((!a), ((int)4), 0);
					
				};
				m_led_54 = a;
				
			};
			if (sw_6) {
				int kick_array_dim = m_kick_array_40.dim;
				int kick_array_channels = m_kick_array_40.channels;
				bool index_ignore_76 = (((int)5) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_76 ? 0 : m_kick_array_40.read(((int)5), 0));
				bool index_ignore_77 = (((int)5) >= kick_array_dim);
				if ((!index_ignore_77)) {
					m_kick_array_40.write((!a), ((int)5), 0);
					
				};
				m_led_53 = a;
				
			};
			if (sw_7) {
				int kick_array_dim = m_kick_array_40.dim;
				int kick_array_channels = m_kick_array_40.channels;
				bool index_ignore_78 = (((int)6) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_78 ? 0 : m_kick_array_40.read(((int)6), 0));
				bool index_ignore_79 = (((int)6) >= kick_array_dim);
				if ((!index_ignore_79)) {
					m_kick_array_40.write((!a), ((int)6), 0);
					
				};
				m_led_52 = a;
				
			};
			if (sw_8) {
				int kick_array_dim = m_kick_array_40.dim;
				int kick_array_channels = m_kick_array_40.channels;
				bool index_ignore_80 = (((int)7) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_80 ? 0 : m_kick_array_40.read(((int)7), 0));
				bool index_ignore_81 = (((int)7) >= kick_array_dim);
				if ((!index_ignore_81)) {
					m_kick_array_40.write((!a), ((int)7), 0);
					
				};
				m_led_51 = a;
				
			};
			t_sample expr_21774 = m_led_58;
			t_sample expr_21775 = m_led_57;
			t_sample expr_21776 = m_led_56;
			t_sample expr_21777 = m_led_55;
			t_sample expr_21778 = m_led_54;
			t_sample expr_21779 = m_led_53;
			t_sample expr_21780 = m_led_52;
			t_sample expr_21781 = m_led_51;
			if ((elapsed == ((int)0))) {
				// for loop initializer;
				int c = ((int)0);
				// for loop condition;
				while ((c < ((int)64))) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					// for loop initializer;
					int i_21800 = ((int)0);
					// for loop condition;
					while ((i_21800 < ((int)8))) {
						// abort processing if an infinite loop is suspected;
						if (((__loopcount--) <= 0)) {
							__exception = GENLIB_ERR_LOOP_OVERFLOW;
							break ;
							
						};
						t_sample noise_22100 = noise();
						t_sample sub_22103 = (noise_22100 - (-1));
						t_sample scale_22099 = ((safepow((sub_22103 * ((t_sample)0.5)), ((int)1)) * ((t_sample)0.85)) + ((t_sample)0.1));
						t_sample noise_22110 = noise();
						t_sample sub_22113 = (noise_22110 - (-1));
						t_sample scale_22109 = ((safepow((sub_22113 * ((t_sample)0.5)), ((int)1)) * ((t_sample)0.85)) + ((t_sample)0.1));
						int snare_patterns_dim = m_snare_patterns_37.dim;
						int snare_patterns_channels = m_snare_patterns_37.channels;
						bool chan_ignore_82 = ((c < 0) || (c >= snare_patterns_channels));
						bool index_ignore_83 = ((i_21800 >= snare_patterns_dim) || (i_21800 < 0));
						if ((!(chan_ignore_82 || index_ignore_83))) {
							m_snare_patterns_37.write(((int)1), i_21800, c);
							
						};
						int snare_hit_values_dim = m_snare_hit_values_34.dim;
						int snare_hit_values_channels = m_snare_hit_values_34.channels;
						bool chan_ignore_84 = ((c < 0) || (c >= snare_hit_values_channels));
						bool index_ignore_85 = ((i_21800 >= snare_hit_values_dim) || (i_21800 < 0));
						if ((!(chan_ignore_84 || index_ignore_85))) {
							m_snare_hit_values_34.write(scale_22099, i_21800, c);
							
						};
						int hihat_patterns_dim = m_hihat_patterns_33.dim;
						int hihat_patterns_channels = m_hihat_patterns_33.channels;
						bool chan_ignore_86 = ((c < 0) || (c >= hihat_patterns_channels));
						bool index_ignore_87 = ((i_21800 >= hihat_patterns_dim) || (i_21800 < 0));
						if ((!(chan_ignore_86 || index_ignore_87))) {
							m_hihat_patterns_33.write(((int)1), i_21800, c);
							
						};
						int hihat_hit_values_dim = m_hihat_hit_values_36.dim;
						int hihat_hit_values_channels = m_hihat_hit_values_36.channels;
						bool chan_ignore_88 = ((c < 0) || (c >= hihat_hit_values_channels));
						bool index_ignore_89 = ((i_21800 >= hihat_hit_values_dim) || (i_21800 < 0));
						if ((!(chan_ignore_88 || index_ignore_89))) {
							m_hihat_hit_values_36.write(scale_22109, i_21800, c);
							
						};
						// for loop increment;
						i_21800 = (i_21800 + ((int)1));
						
					};
					// for loop increment;
					c = (c + ((int)1));
					
				};
				
			};
			t_sample out29 = expr_21771;
			t_sample out30 = expr_21772;
			t_sample noise_19099 = noise();
			t_sample mix_22133 = (noise_19099 + (((t_sample)0.5) * (m_history_5 - noise_19099)));
			t_sample mix_19076 = mix_22133;
			t_sample mix_22134 = (mix_19076 + (((t_sample)0.6) * (m_history_4 - mix_19076)));
			t_sample mix_19097 = mix_22134;
			t_sample noise_19116 = noise();
			t_sample mix_22135 = (noise_19116 + (((t_sample)0.7) * (m_history_3 - noise_19116)));
			t_sample mix_19114 = mix_22135;
			int or_18928 = (((int)0) || (elapsed == ((int)0)));
			t_sample switch_18930 = (or_18928 ? ((t_sample)0.41) : m_y_26);
			t_sample mul_18943 = (switch_18930 * ((int)1));
			t_sample switch_18929 = (or_18928 ? ((t_sample)0.1) : m_x_25);
			t_sample switch_18931 = (or_18928 ? ((t_sample)0.31) : m_z_24);
			t_sample mul_18948 = (switch_18931 * ((int)1));
			t_sample mul_18951 = (mul_18948 * ((t_sample)0.0002));
			t_sample add_18945 = (switch_18930 + mul_18951);
			t_sample fixnan_18934 = fixnan(add_18945);
			t_sample gen_18957 = fixnan_18934;
			t_sample mul_18952 = (mul_18943 * ((t_sample)0.0002));
			t_sample add_18946 = (switch_18929 + mul_18952);
			t_sample fixnan_18932 = fixnan(add_18946);
			t_sample mul_18940 = (switch_18931 * (-0.45));
			t_sample pow_18938 = safepow(switch_18929, ((int)3));
			t_sample mul_18939 = (pow_18938 * (-1));
			t_sample mul_18942 = (switch_18929 * ((t_sample)0.8));
			t_sample mul_18941 = (switch_18930 * (-1.1));
			t_sample add_18937 = (mul_18942 + mul_18941);
			t_sample add_18936 = (add_18937 + mul_18940);
			t_sample add_18935 = (add_18936 + mul_18939);
			t_sample mul_18950 = (add_18935 * ((t_sample)0.0002));
			t_sample add_18944 = (switch_18931 + mul_18950);
			t_sample fixnan_18933 = fixnan(add_18944);
			t_sample y_next_18953 = fixdenorm(fixnan_18934);
			t_sample x_next_18954 = fixdenorm(fixnan_18932);
			t_sample z_next_18955 = fixdenorm(fixnan_18933);
			t_sample elapsed_18960 = elapsed;
			int eq_18959 = (elapsed_18960 == ((int)0));
			int or_18967 = (eq_18959 || ((int)0));
			t_sample switch_18963 = (or_18967 ? ((int)10000000000) : m_history_23);
			t_sample min_18966 = ((switch_18963 < gen_18957) ? switch_18963 : gen_18957);
			t_sample gen_18970 = min_18966;
			t_sample switch_18962 = (or_18967 ? iftrue_90 : m_history_22);
			t_sample max_18965 = ((gen_18957 < switch_18962) ? switch_18962 : gen_18957);
			t_sample gen_18971 = max_18965;
			t_sample history_18961_next_18968 = fixdenorm(min_18966);
			t_sample history_18964_next_18969 = fixdenorm(max_18965);
			t_sample irange_22137 = (gen_18971 - gen_18970);
			t_sample sub_22139 = (gen_18957 - gen_18970);
			t_sample scale_22136 = ((safepow(safediv(sub_22139, irange_22137), ((int)1)) * ((int)2)) + ((int)-1));
			t_sample scale_18972 = scale_22136;
			t_sample gen_18973 = scale_18972;
			t_sample mul_18920 = (m_knob4_swing_47 * gen_18973);
			t_sample out33 = mul_18920;
			t_sample sub_19112 = (noise_19116 - mix_19114);
			t_sample mul_18926 = (div_18922 * mul_18920);
			t_sample add_18921 = (div_18922 + mul_18926);
			t_sample add_18925 = (m_history_2 + add_18921);
			t_sample wrap_18923 = wrap(add_18925, ((int)0), ((int)1));
			t_sample mul_19167 = (wrap_18923 * ((int)8));
			t_sample floor_19166 = floor(mul_19167);
			t_sample out28 = floor_19166;
			t_sample sub_19074 = (mix_19076 - mix_19097);
			t_sample wrap_19143 = wrap(mul_19167, ((int)0), ((int)1));
			t_sample delta_19118 = __m_delta_91(wrap_19143);
			t_sample abs_19122 = fabs(delta_19118);
			int gt_19121 = (abs_19122 > ((t_sample)0.5));
			int change_19120 = __m_change_92(gt_19121);
			int gt_19119 = (change_19120 > ((int)0));
			int trigger_beat_18976 = gt_19119;
			int trigger_beat_19142 = trigger_beat_18976;
			int trig = (__m_change_93((trigger_beat_19142 > ((int)0))) > ((int)0));
			if (trig) {
				int snare_array_dim = m_snare_array_45.dim;
				int snare_array_channels = m_snare_array_45.channels;
				// samples snare_array channel 1;
				m_hit_1_snare_21 = m_snare_array_45.read(0, 0);
				bool index_ignore_94 = (((int)1) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_2_snare_20 = (index_ignore_94 ? 0 : m_snare_array_45.read(((int)1), 0));
				bool index_ignore_95 = (((int)2) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_3_snare_19 = (index_ignore_95 ? 0 : m_snare_array_45.read(((int)2), 0));
				bool index_ignore_96 = (((int)3) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_4_snare_18 = (index_ignore_96 ? 0 : m_snare_array_45.read(((int)3), 0));
				bool index_ignore_97 = (((int)4) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_5_snare_17 = (index_ignore_97 ? 0 : m_snare_array_45.read(((int)4), 0));
				bool index_ignore_98 = (((int)5) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_6_snare_16 = (index_ignore_98 ? 0 : m_snare_array_45.read(((int)5), 0));
				bool index_ignore_99 = (((int)6) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_7_snare_15 = (index_ignore_99 ? 0 : m_snare_array_45.read(((int)6), 0));
				bool index_ignore_100 = (((int)7) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_8_snare_14 = (index_ignore_100 ? 0 : m_snare_array_45.read(((int)7), 0));
				int hihat_array_dim = m_hihat_array_42.dim;
				int hihat_array_channels = m_hihat_array_42.channels;
				// samples hihat_array channel 1;
				m_hit_1_hihat_13 = m_hihat_array_42.read(0, 0);
				bool index_ignore_101 = (((int)1) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_2_hihat_12 = (index_ignore_101 ? 0 : m_hihat_array_42.read(((int)1), 0));
				bool index_ignore_102 = (((int)2) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_3_hihat_11 = (index_ignore_102 ? 0 : m_hihat_array_42.read(((int)2), 0));
				bool index_ignore_103 = (((int)3) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_4_hihat_10 = (index_ignore_103 ? 0 : m_hihat_array_42.read(((int)3), 0));
				bool index_ignore_104 = (((int)4) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_5_hihat_9 = (index_ignore_104 ? 0 : m_hihat_array_42.read(((int)4), 0));
				bool index_ignore_105 = (((int)5) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_6_hihat_8 = (index_ignore_105 ? 0 : m_hihat_array_42.read(((int)5), 0));
				bool index_ignore_106 = (((int)6) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_7_hihat_7 = (index_ignore_106 ? 0 : m_hihat_array_42.read(((int)6), 0));
				bool index_ignore_107 = (((int)7) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_8_hihat_6 = (index_ignore_107 ? 0 : m_hihat_array_42.read(((int)7), 0));
				// for loop initializer;
				int i_21802 = ((int)0);
				// for loop condition;
				while ((i_21802 < snare_array_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					t_sample sub_22147 = (m_knob2_X_43 - ((int)0));
					t_sample scale_22144 = ((safepow((sub_22147 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample sub_22151 = (m_knob3_Y_41 - ((int)0));
					t_sample scale_22148 = ((safepow((sub_22151 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample c_21801 = (round(scale_22144) + round((scale_22148 * ((int)8))));
					int snare_patterns_dim = m_snare_patterns_37.dim;
					int snare_patterns_channels = m_snare_patterns_37.channels;
					bool index_ignore_108 = ((i_21802 >= snare_patterns_dim) || (i_21802 < 0));
					// samples snare_patterns channel 1;
					int chan_109 = c_21801;
					bool chan_ignore_110 = ((chan_109 < 0) || (chan_109 >= snare_patterns_channels));
					t_sample h = ((chan_ignore_110 || index_ignore_108) ? 0 : m_snare_patterns_37.read(i_21802, chan_109));
					int snare_hit_values_dim = m_snare_hit_values_34.dim;
					int snare_hit_values_channels = m_snare_hit_values_34.channels;
					bool index_ignore_111 = ((i_21802 >= snare_hit_values_dim) || (i_21802 < 0));
					// samples snare_hit_values channel 1;
					int chan_112 = c_21801;
					bool chan_ignore_113 = ((chan_112 < 0) || (chan_112 >= snare_hit_values_channels));
					t_sample v = ((chan_ignore_113 || index_ignore_111) ? 0 : m_snare_hit_values_34.read(i_21802, chan_112));
					int hit = ((int)0);
					if (((v < (((int)1) - m_knob5_snareDensity_38)) && (h == ((int)1)))) {
						hit = ((int)1);
						
					};
					bool index_ignore_114 = ((i_21802 >= snare_array_dim) || (i_21802 < 0));
					if ((!index_ignore_114)) {
						m_snare_array_45.write(hit, i_21802, 0);
						
					};
					bool chan_ignore_115 = ((((int)1) < 0) || (((int)1) >= snare_array_channels));
					bool index_ignore_116 = ((i_21802 >= snare_array_dim) || (i_21802 < 0));
					if ((!(chan_ignore_115 || index_ignore_116))) {
						m_snare_array_45.write(v, i_21802, ((int)1));
						
					};
					// for loop increment;
					i_21802 = (i_21802 + ((int)1));
					
				};
				// for loop initializer;
				i_21802 = ((int)0);
				// for loop condition;
				while ((i_21802 < hihat_array_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					t_sample sub_22155 = (m_knob2_X_43 - ((int)0));
					t_sample scale_22152 = ((safepow((sub_22155 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample sub_22159 = (m_knob3_Y_41 - ((int)0));
					t_sample scale_22156 = ((safepow((sub_22159 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample c_21801 = (round(scale_22152) + round((scale_22156 * ((int)8))));
					int hihat_patterns_dim = m_hihat_patterns_33.dim;
					int hihat_patterns_channels = m_hihat_patterns_33.channels;
					bool index_ignore_117 = ((i_21802 >= hihat_patterns_dim) || (i_21802 < 0));
					// samples hihat_patterns channel 1;
					int chan_118 = c_21801;
					bool chan_ignore_119 = ((chan_118 < 0) || (chan_118 >= hihat_patterns_channels));
					t_sample h = ((chan_ignore_119 || index_ignore_117) ? 0 : m_hihat_patterns_33.read(i_21802, chan_118));
					int hihat_hit_values_dim = m_hihat_hit_values_36.dim;
					int hihat_hit_values_channels = m_hihat_hit_values_36.channels;
					bool index_ignore_120 = ((i_21802 >= hihat_hit_values_dim) || (i_21802 < 0));
					// samples hihat_hit_values channel 1;
					int chan_121 = c_21801;
					bool chan_ignore_122 = ((chan_121 < 0) || (chan_121 >= hihat_hit_values_channels));
					t_sample v = ((chan_ignore_122 || index_ignore_120) ? 0 : m_hihat_hit_values_36.read(i_21802, chan_121));
					int hit = ((int)0);
					if (((v < (((int)1) - m_knob6_hihatDensity_44)) && (h == ((int)1)))) {
						hit = ((int)1);
						
					};
					bool index_ignore_123 = ((i_21802 >= hihat_array_dim) || (i_21802 < 0));
					if ((!index_ignore_123)) {
						m_hihat_array_42.write(hit, i_21802, 0);
						
					};
					bool chan_ignore_124 = ((((int)1) < 0) || (((int)1) >= hihat_array_channels));
					bool index_ignore_125 = ((i_21802 >= hihat_array_dim) || (i_21802 < 0));
					if ((!(chan_ignore_124 || index_ignore_125))) {
						m_hihat_array_42.write(v, i_21802, ((int)1));
						
					};
					// for loop increment;
					i_21802 = (i_21802 + ((int)1));
					
				};
				
			};
			t_sample expr_21784 = m_hit_1_snare_21;
			t_sample expr_21785 = m_hit_2_snare_20;
			t_sample expr_21786 = m_hit_3_snare_19;
			t_sample expr_21787 = m_hit_4_snare_18;
			t_sample expr_21788 = m_hit_5_snare_17;
			t_sample expr_21789 = m_hit_6_snare_16;
			t_sample expr_21790 = m_hit_7_snare_15;
			t_sample expr_21791 = m_hit_8_snare_14;
			t_sample expr_21792 = m_hit_1_hihat_13;
			t_sample expr_21793 = m_hit_2_hihat_12;
			t_sample expr_21794 = m_hit_3_hihat_11;
			t_sample expr_21795 = m_hit_4_hihat_10;
			t_sample expr_21796 = m_hit_5_hihat_9;
			t_sample expr_21797 = m_hit_6_hihat_8;
			t_sample expr_21798 = m_hit_7_hihat_7;
			t_sample expr_21799 = m_hit_8_hihat_6;
			t_sample out25 = expr_21798;
			t_sample out20 = expr_21793;
			t_sample out22 = expr_21795;
			t_sample out23 = expr_21796;
			t_sample out19 = expr_21792;
			t_sample out11 = expr_21784;
			t_sample out14 = expr_21787;
			t_sample out18 = expr_21791;
			t_sample out16 = expr_21789;
			t_sample out12 = expr_21785;
			t_sample out21 = expr_21794;
			t_sample out17 = expr_21790;
			t_sample out24 = expr_21797;
			t_sample out26 = expr_21799;
			t_sample out15 = expr_21788;
			t_sample out13 = expr_21786;
			t_sample out27 = trigger_beat_19142;
			int trigger_beat_19039 = trigger_beat_18976;
			__m_latch_126 = ((trigger_beat_19039 != 0) ? floor_19166 : __m_latch_126);
			t_sample latch_19040 = __m_latch_126;
			int eq_19031 = (latch_19040 == ((int)7));
			t_sample out10 = (eq_19031 + expr_21781);
			int eq_19038 = (latch_19040 == ((int)0));
			t_sample out3 = (eq_19038 + expr_21774);
			int eq_19037 = (latch_19040 == ((int)1));
			t_sample out4 = (eq_19037 + expr_21775);
			int eq_19036 = (latch_19040 == ((int)2));
			t_sample out5 = (eq_19036 + expr_21776);
			int eq_19034 = (latch_19040 == ((int)4));
			t_sample out7 = (eq_19034 + expr_21778);
			int eq_19032 = (latch_19040 == ((int)6));
			t_sample out9 = (eq_19032 + expr_21780);
			int eq_19033 = (latch_19040 == ((int)5));
			t_sample out8 = (eq_19033 + expr_21779);
			int eq_19035 = (latch_19040 == ((int)3));
			t_sample out6 = (eq_19035 + expr_21777);
			int gt_18984 = (trigger_beat_18976 > ((int)0));
			int change_18983 = __m_change_127(gt_18984);
			int gt_18982 = (change_18983 > ((int)0));
			int plusequals_18981 = __m_pluseq_128.post(((int)1), gt_18982, 0);
			int lte_18980 = (plusequals_18981 <= max_18978);
			t_sample out34 = lte_18980;
			t_sample phasor_19006 = __m_phasor_129(((int)5000), samples_to_seconds);
			t_sample delta_19001 = __m_delta_130(phasor_19006);
			t_sample abs_19005 = fabs(delta_19001);
			int gt_19004 = (abs_19005 > ((t_sample)0.5));
			int change_19003 = __m_change_131(gt_19004);
			int gt_19002 = (change_19003 > ((int)0));
			__m_count_132 = (((int)0) ? 0 : (fixdenorm(__m_count_132 + gt_19002)));
			int carry_133 = 0;
			if ((((int)0) != 0)) {
				__m_count_132 = 0;
				__m_carry_134 = 0;
				
			} else if (((((int)63) > 0) && (__m_count_132 >= ((int)63)))) {
				int wraps_135 = (__m_count_132 / ((int)63));
				__m_carry_134 = (__m_carry_134 + wraps_135);
				__m_count_132 = (__m_count_132 - (wraps_135 * ((int)63)));
				carry_133 = 1;
				
			};
			int counter_19010 = __m_count_132;
			int counter_19011 = carry_133;
			int counter_19012 = __m_carry_134;
			int add_19000 = (counter_19010 + ((int)1));
			t_sample out31 = add_19000;
			bool index_ignore_136 = ((counter_19010 >= grid_matrix_noise_dim) || (counter_19010 < 0));
			// samples grid_matrix_noise channel 1;
			t_sample sample_grid_matrix_noise_19007 = (index_ignore_136 ? 0 : m_grid_matrix_noise_48.read(counter_19010, 0));
			t_sample index_grid_matrix_noise_19008 = counter_19010;
			t_sample out32 = sample_grid_matrix_noise_19007;
			t_sample phasor_19093 = __m_phasor_137(((int)330), samples_to_seconds);
			t_sample triangle_19092 = triangle(phasor_19093, ((t_sample)0.5));
			t_sample phasor_19091 = __m_phasor_138(((int)185), samples_to_seconds);
			t_sample triangle_19090 = triangle(phasor_19091, ((t_sample)0.5));
			int trigger_beat_19029 = trigger_beat_18976;
			t_sample delta_19123 = __m_delta_139(wrap_18923);
			t_sample abs_19127 = fabs(delta_19123);
			int gt_19126 = (abs_19127 > ((t_sample)0.5));
			int change_19125 = __m_change_140(gt_19126);
			int gt_19124 = (change_19125 > ((int)0));
			int trigger_master_19130 = gt_19124;
			__m_count_141 = (trigger_master_19130 ? 0 : (fixdenorm(__m_count_141 + gt_19119)));
			int counter_19133 = __m_count_141;
			int counter_19134 = ((int)0);
			int counter_19135 = ((int)0);
			bool index_ignore_142 = ((counter_19133 >= kick_array_dim) || (counter_19133 < 0));
			// samples kick_array channel 1;
			t_sample sample_kick_array_19056 = (index_ignore_142 ? 0 : m_kick_array_40.read(counter_19133, 0));
			t_sample index_kick_array_19057 = counter_19133;
			t_sample kick_boolean_19055 = sample_kick_array_19056;
			__m_latch_143 = ((kick_boolean_19055 != 0) ? trigger_beat_19029 : __m_latch_143);
			t_sample latch_19054 = __m_latch_143;
			t_sample delta_19069 = __m_delta_144(latch_19054);
			t_sample abs_19045 = fabs(delta_19069);
			int gt_19044 = (abs_19045 > ((t_sample)0.5));
			int change_19043 = __m_change_145(gt_19044);
			int gt_19042 = (change_19043 > ((int)0));
			t_sample plusequals_19047 = __m_pluseq_146.post(safediv(8, samplerate), gt_19042, 0);
			t_sample clamp_19046 = ((plusequals_19047 <= ((int)0)) ? ((int)0) : ((plusequals_19047 >= ((int)1)) ? ((int)1) : plusequals_19047));
			t_sample sub_22163 = (clamp_19046 - ((int)0));
			t_sample scale_22160 = ((safepow((sub_22163 * ((t_sample)1)), (1 * ((t_sample)0.25))) * ((int)-1)) + ((int)1));
			t_sample scale_19048 = scale_22160;
			t_sample sub_22167 = (scale_19048 - ((int)1));
			t_sample scale_22164 = ((safepow((sub_22167 * ((t_sample)-1)), ((int)1)) * ((int)-100)) + ((int)150));
			t_sample scale_19051 = scale_22164;
			t_sample sin_19052 = sin(scale_19051);
			t_sample mul_19053 = (scale_19048 * sin_19052);
			t_sample mix_22168 = (mul_19053 + (((t_sample)0.9) * (m_history_1 - mul_19053)));
			t_sample mix_19050 = mix_22168;
			bool index_ignore_147 = ((counter_19133 >= hihat_array_dim) || (counter_19133 < 0));
			// samples hihat_array channel 1;
			t_sample sample_hihat_array_19131 = (index_ignore_147 ? 0 : m_hihat_array_42.read(counter_19133, 0));
			t_sample index_hihat_array_19132 = counter_19133;
			__m_latch_148 = ((sample_hihat_array_19131 != 0) ? trigger_beat_18976 : __m_latch_148);
			t_sample latch_19136 = __m_latch_148;
			t_sample delta_19101 = __m_delta_149(latch_19136);
			t_sample abs_19105 = fabs(delta_19101);
			int gt_19104 = (abs_19105 > ((t_sample)0.5));
			int change_19103 = __m_change_150(gt_19104);
			int gt_19102 = (change_19103 > ((int)0));
			t_sample plusequals_19111 = __m_pluseq_151.post(((t_sample)0.0003239390994493), gt_19102, 0);
			t_sample clamp_19110 = ((plusequals_19111 <= ((int)0)) ? ((int)0) : ((plusequals_19111 >= ((int)1)) ? ((int)1) : plusequals_19111));
			t_sample sub_22172 = (clamp_19110 - ((int)0));
			t_sample scale_22169 = ((safepow((sub_22172 * ((t_sample)1)), (1 * ((t_sample)0.25))) * ((int)-1)) + ((int)1));
			t_sample mul_19115 = (scale_22169 * sub_19112);
			bool index_ignore_152 = ((counter_19133 >= snare_array_dim) || (counter_19133 < 0));
			// samples snare_array channel 1;
			t_sample sample_snare_array_19144 = (index_ignore_152 ? 0 : m_snare_array_45.read(counter_19133, 0));
			t_sample index_snare_array_19145 = counter_19133;
			__m_latch_153 = ((sample_snare_array_19144 != 0) ? trigger_beat_18976 : __m_latch_153);
			t_sample latch_19140 = __m_latch_153;
			t_sample delta_19028 = __m_delta_154(latch_19140);
			t_sample abs_19073 = fabs(delta_19028);
			int gt_19072 = (abs_19073 > ((t_sample)0.5));
			int change_19071 = __m_change_155(gt_19072);
			int gt_19070 = (change_19071 > ((int)0));
			t_sample plusequals_19095 = __m_pluseq_156.post(safediv(13, samplerate), gt_19070, 0);
			t_sample clamp_19094 = ((plusequals_19095 <= ((int)0)) ? ((int)0) : ((plusequals_19095 >= ((int)1)) ? ((int)1) : plusequals_19095));
			t_sample sub_22176 = (clamp_19094 - ((int)0));
			t_sample scale_22173 = ((safepow((sub_22176 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((int)-1)) + ((int)1));
			t_sample mul_19098 = (scale_22173 * triangle_19092);
			t_sample plusequals_19080 = __m_pluseq_157.post(safediv(7, samplerate), gt_19070, 0);
			t_sample clamp_19078 = ((plusequals_19080 <= ((int)0)) ? ((int)0) : ((plusequals_19080 >= ((int)1)) ? ((int)1) : plusequals_19080));
			t_sample sub_22180 = (clamp_19078 - ((int)0));
			t_sample scale_22177 = ((safepow((sub_22180 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((t_sample)-0.5)) + ((t_sample)0.5));
			t_sample mul_19077 = (scale_22177 * sub_19074);
			t_sample plusequals_19088 = __m_pluseq_158.post(safediv(8, samplerate), gt_19070, 0);
			t_sample clamp_19084 = ((plusequals_19088 <= ((int)0)) ? ((int)0) : ((plusequals_19088 >= ((int)1)) ? ((int)1) : plusequals_19088));
			t_sample sub_22184 = (clamp_19084 - ((int)0));
			t_sample scale_22181 = ((safepow((sub_22184 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((t_sample)-0.7)) + ((t_sample)0.7));
			t_sample mul_19082 = (scale_22181 * mix_19076);
			t_sample plusequals_19089 = __m_pluseq_159.post(safediv(11, samplerate), gt_19070, 0);
			t_sample clamp_19086 = ((plusequals_19089 <= ((int)0)) ? ((int)0) : ((plusequals_19089 >= ((int)1)) ? ((int)1) : plusequals_19089));
			t_sample sub_22188 = (clamp_19086 - ((int)0));
			t_sample scale_22185 = ((safepow((sub_22188 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((int)-1)) + ((int)1));
			t_sample mul_19083 = (scale_22185 * triangle_19090);
			t_sample v_160 = (((mul_19083 + mul_19082) + mul_19077) + mul_19098);
			t_sample clamp_19081 = ((v_160 <= min_161) ? min_161 : ((v_160 >= ((int)1)) ? ((int)1) : v_160));
			t_sample add_18995 = (mul_19115 + clamp_19081);
			t_sample mul_18987 = (add_18995 * ((t_sample)0.5));
			t_sample add_18994 = (mul_18987 + mix_19050);
			t_sample mul_18986 = (add_18994 * ((t_sample)0.5));
			t_sample mix_22189 = (mul_18986 + (((t_sample)0.5) * (in1 - mul_18986)));
			t_sample out1 = mix_22189;
			t_sample add_18992 = (mul_19115 + clamp_19081);
			t_sample mul_18988 = (add_18992 * ((t_sample)0.5));
			t_sample add_18991 = (mul_18988 + mix_19050);
			t_sample mul_18985 = (add_18991 * ((t_sample)0.5));
			t_sample mix_22190 = (mul_18985 + (((t_sample)0.5) * (in2 - mul_18985)));
			t_sample out2 = mix_22190;
			t_sample history_19075_next_21803 = fixdenorm(mix_19076);
			t_sample history_19096_next_21804 = fixdenorm(mix_19097);
			t_sample history_19113_next_21805 = fixdenorm(mix_19114);
			t_sample history_18924_next_21806 = fixdenorm(wrap_18923);
			t_sample history_19049_next_21807 = fixdenorm(mix_19050);
			m_y_26 = y_next_18953;
			m_z_24 = z_next_18955;
			m_x_25 = x_next_18954;
			m_history_23 = history_18961_next_18968;
			m_history_22 = history_18964_next_18969;
			m_history_5 = history_19075_next_21803;
			m_history_4 = history_19096_next_21804;
			m_history_3 = history_19113_next_21805;
			m_history_2 = history_18924_next_21806;
			m_history_1 = history_19049_next_21807;
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
			(*(__out13++)) = out13;
			(*(__out14++)) = out14;
			(*(__out15++)) = out15;
			(*(__out16++)) = out16;
			(*(__out17++)) = out17;
			(*(__out18++)) = out18;
			(*(__out19++)) = out19;
			(*(__out20++)) = out20;
			(*(__out21++)) = out21;
			(*(__out22++)) = out22;
			(*(__out23++)) = out23;
			(*(__out24++)) = out24;
			(*(__out25++)) = out25;
			(*(__out26++)) = out26;
			(*(__out27++)) = out27;
			(*(__out28++)) = out28;
			(*(__out29++)) = out29;
			(*(__out30++)) = out30;
			(*(__out31++)) = out31;
			(*(__out32++)) = out32;
			(*(__out33++)) = out33;
			(*(__out34++)) = out34;
			
		};
		return __exception;
		
	};
	inline void set_noise_array(void * _value) {
		m_noise_array_27.setbuffer(_value);
	};
	inline void set_sw8(t_param _value) {
		m_sw_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw3(t_param _value) {
		m_sw_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw4(t_param _value) {
		m_sw_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_hihat_patterns(void * _value) {
		m_hihat_patterns_33.setbuffer(_value);
	};
	inline void set_snare_hit_values(void * _value) {
		m_snare_hit_values_34.setbuffer(_value);
	};
	inline void set_sw7(t_param _value) {
		m_sw_35 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_hihat_hit_values(void * _value) {
		m_hihat_hit_values_36.setbuffer(_value);
	};
	inline void set_snare_patterns(void * _value) {
		m_snare_patterns_37.setbuffer(_value);
	};
	inline void set_knob5_snareDensity(t_param _value) {
		m_knob5_snareDensity_38 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_mix(t_param _value) {
		m_mix_39 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_kick_array(void * _value) {
		m_kick_array_40.setbuffer(_value);
	};
	inline void set_knob3_Y(t_param _value) {
		m_knob3_Y_41 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_hihat_array(void * _value) {
		m_hihat_array_42.setbuffer(_value);
	};
	inline void set_knob2_X(t_param _value) {
		m_knob2_X_43 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_hihatDensity(t_param _value) {
		m_knob6_hihatDensity_44 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_snare_array(void * _value) {
		m_snare_array_45.setbuffer(_value);
	};
	inline void set_knob1_bpm(t_param _value) {
		m_knob1_bpm_46 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_swing(t_param _value) {
		m_knob4_swing_47 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_grid_matrix_noise(void * _value) {
		m_grid_matrix_noise_48.setbuffer(_value);
	};
	inline void set_sw2(t_param _value) {
		m_sw_49 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw6(t_param _value) {
		m_sw_50 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 34;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 24; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "audio_l", "audio_r" };
const char *gen_kernel_outnames[] = { "sound_l", "sound_r", "led1", "led2", "led3", "led4", "led5", "led6", "led7", "led8", "sn1", "sn2", "sn3", "sn4", "sn5", "sn6", "sn7", "sn8", "hi1", "hi2", "hi3", "hi4", "hi5", "hi6", "hi7", "hi8", "trigger_b", "step_value", "x_pos", "y_pos", "out31", "out32", "cvout1", "gateout2" };

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
		case 0: self->set_grid_matrix_noise(ref); break;
		case 1: self->set_hihat_array(ref); break;
		case 2: self->set_hihat_hit_values(ref); break;
		case 3: self->set_hihat_patterns(ref); break;
		case 4: self->set_kick_array(ref); break;
		case 5: self->set_knob1_bpm(value); break;
		case 6: self->set_knob2_X(value); break;
		case 7: self->set_knob3_Y(value); break;
		case 8: self->set_knob4_swing(value); break;
		case 9: self->set_knob5_snareDensity(value); break;
		case 10: self->set_knob6_hihatDensity(value); break;
		case 11: self->set_mix(value); break;
		case 12: self->set_noise_array(ref); break;
		case 13: self->set_snare_array(ref); break;
		case 14: self->set_snare_hit_values(ref); break;
		case 15: self->set_snare_patterns(ref); break;
		case 16: self->set_sw1(value); break;
		case 17: self->set_sw2(value); break;
		case 18: self->set_sw3(value); break;
		case 19: self->set_sw4(value); break;
		case 20: self->set_sw5(value); break;
		case 21: self->set_sw6(value); break;
		case 22: self->set_sw7(value); break;
		case 23: self->set_sw8(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		
		
		
		
		
		case 5: *value = self->m_knob1_bpm_46; break;
		case 6: *value = self->m_knob2_X_43; break;
		case 7: *value = self->m_knob3_Y_41; break;
		case 8: *value = self->m_knob4_swing_47; break;
		case 9: *value = self->m_knob5_snareDensity_38; break;
		case 10: *value = self->m_knob6_hihatDensity_44; break;
		case 11: *value = self->m_mix_39; break;
		
		
		
		
		case 16: *value = self->m_sw_31; break;
		case 17: *value = self->m_sw_49; break;
		case 18: *value = self->m_sw_30; break;
		case 19: *value = self->m_sw_32; break;
		case 20: *value = self->m_sw_29; break;
		case 21: *value = self->m_sw_50; break;
		case 22: *value = self->m_sw_35; break;
		case 23: *value = self->m_sw_28; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(24 * sizeof(ParamInfo));
	self->__commonstate.numparams = 24;
	// initialize parameter 0 ("m_grid_matrix_noise_48")
	pi = self->__commonstate.params + 0;
	pi->name = "grid_matrix_noise";
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
	// initialize parameter 1 ("m_hihat_array_42")
	pi = self->__commonstate.params + 1;
	pi->name = "hihat_array";
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
	// initialize parameter 2 ("m_hihat_hit_values_36")
	pi = self->__commonstate.params + 2;
	pi->name = "hihat_hit_values";
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
	// initialize parameter 3 ("m_hihat_patterns_33")
	pi = self->__commonstate.params + 3;
	pi->name = "hihat_patterns";
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
	// initialize parameter 4 ("m_kick_array_40")
	pi = self->__commonstate.params + 4;
	pi->name = "kick_array";
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
	// initialize parameter 5 ("m_knob1_bpm_46")
	pi = self->__commonstate.params + 5;
	pi->name = "knob1_bpm";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_bpm_46;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_knob2_X_43")
	pi = self->__commonstate.params + 6;
	pi->name = "knob2_X";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob2_X_43;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_knob3_Y_41")
	pi = self->__commonstate.params + 7;
	pi->name = "knob3_Y";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_Y_41;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_knob4_swing_47")
	pi = self->__commonstate.params + 8;
	pi->name = "knob4_swing";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_swing_47;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_knob5_snareDensity_38")
	pi = self->__commonstate.params + 9;
	pi->name = "knob5_snareDensity";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_snareDensity_38;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_knob6_hihatDensity_44")
	pi = self->__commonstate.params + 10;
	pi->name = "knob6_hihatDensity";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_hihatDensity_44;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_mix_39")
	pi = self->__commonstate.params + 11;
	pi->name = "mix";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_mix_39;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_noise_array_27")
	pi = self->__commonstate.params + 12;
	pi->name = "noise_array";
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
	// initialize parameter 13 ("m_snare_array_45")
	pi = self->__commonstate.params + 13;
	pi->name = "snare_array";
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
	// initialize parameter 14 ("m_snare_hit_values_34")
	pi = self->__commonstate.params + 14;
	pi->name = "snare_hit_values";
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
	// initialize parameter 15 ("m_snare_patterns_37")
	pi = self->__commonstate.params + 15;
	pi->name = "snare_patterns";
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
	// initialize parameter 16 ("m_sw_31")
	pi = self->__commonstate.params + 16;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_31;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 17 ("m_sw_49")
	pi = self->__commonstate.params + 17;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_49;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 18 ("m_sw_30")
	pi = self->__commonstate.params + 18;
	pi->name = "sw3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 19 ("m_sw_32")
	pi = self->__commonstate.params + 19;
	pi->name = "sw4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_32;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 20 ("m_sw_29")
	pi = self->__commonstate.params + 20;
	pi->name = "sw5";
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
	// initialize parameter 21 ("m_sw_50")
	pi = self->__commonstate.params + 21;
	pi->name = "sw6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_50;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 22 ("m_sw_35")
	pi = self->__commonstate.params + 22;
	pi->name = "sw7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_35;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 23 ("m_sw_28")
	pi = self->__commonstate.params + 23;
	pi->name = "sw8";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_28;
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


} // KHAIROS::
