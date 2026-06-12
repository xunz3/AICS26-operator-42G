BangC 评测报告
队伍: 87  |  任务 ID: 02c0d12f-63f6-4996-8247-bf4ea0aaad54  |  时间: 2026-06-12T08:08:45.887336+00:00

仓库: xunz3/AICS26-operator-42G  |  Commit: ddba7aa4

📄 config 文件内容
001
002
003
004
005
009
012
023
034
039
051
056
070
075
103
104
109
111
135
138
📂 仓库文件列表（共 23 个文件）
Argmax_over_a_dimension.mlu
BatchNorm.mlu
Dilated_conv_2D.mlu
GRU_forward.mlu
KL_Divergence_Loss.mlu
LeakyReLU.mlu
LogSoftmax.mlu
MSE_Loss.mlu
Masked_select.mlu
Matrix_vector_multiplication_.mlu
README.md
Scatter_add.mlu
Sqrt.mlu
TopK.mlu
average_pooling_2d.mlu
bangc_scalar.h
batched_matrix_multiplication.mlu
config
conv_standard_1D.mlu
conv_transposed_2D__asymmetric_input__square_kernel.mlu
cumsum.mlu
gather.mlu
matrix_scalar_multiplication.mlu
📊 评测总览


题目	得分	精度检查	延迟	状态
001_LeakyReLU	0.012	PASS (diff=1.46e-05)	2307.445 us	✅
002_matrix_scalar_multiplication	0.334	PASS (diff=1.59e-03)	24810.924 us	✅
003_LogSoftmax	0.000	PASS (diff=3.91e-03)	96186.149 us	✅
004_batched_matrix_multiplication	0.000	—	N/A	❌
005_average_pooling_2d	0.001	PASS (diff=2.42e-04)	6770748.007 us	✅
009_conv_standard_1D	0.000	PASS (diff=7.62e-03)	502095.363 us	✅
012_conv_transposed_2D__asymmetric_input__square_kernel	0.000	—	N/A	❌
023_Matrix_vector_multiplication_	0.000	FAIL (diff=3.56e-01)	178536.253 us	❌
034_Argmax_over_a_dimension	0.000	PASS (diff=0.00e+00)	101660.639 us	✅
039_BatchNorm	0.000	PASS (diff=1.00e-03)	20649484.800 us	✅
051_cumsum	0.000	PASS (diff=4.58e-05)	96190.000 us	✅
056_gather	0.000	FAIL (diff=2.48e+01)	4444.870 us	❌
070_Sqrt	0.018	PASS (diff=4.88e-04)	2219.588 us	✅
075_TopK	0.000	PASS (diff=0.00e+00)	72139.097 us	✅
103_MSE_Loss	0.000	—	N/A	❌
104_KL_Divergence_Loss	0.000	—	N/A	❌
109_Scatter_add	0.000	—	N/A	❌
111_Masked_select	0.000	—	N/A	❌
135_Dilated_conv_2D	0.000	—	N/A	❌
138_GRU_forward	0.000	—	N/A	❌
汇总: 提交20 题，通过 10 题

📋 详情
001_LeakyReLU — 得分: 0.012 | PASS (diff=1.46e-05)
输出:

=== stdout ===
[run 1]
[1/2] /usr/local/neuware/bin/cncc -c /root/.cache/torch_extensions/py310_cpu/LeakyReLU/bang.mlu -o bang.mlu.o -DTORCH_EXTENSION_NAME=LeakyReLU -DTORCH_API_INCLUDE_EXTENSION_H -DPYBIND11_COMPILER_TYPE=\"_gcc\" -DPYBIND11_STDLIB=\"_libstdcpp\" -DPYBIND11_BUILD_ABI=\"_cxxabi1011\" -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/torch/csrc/api/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/TH -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/THC -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/api/include/torch_mlu -isystem /usr/local/neuware/include -isystem /opt/py3.10/include/python3.10 -D_GLIBCXX_USE_CXX11_ABI=0 --bang-arch=compute_30 --no-neuware-version-check -fPIC -O3 -lm --neuware-path=/usr/local/neuware -std=c++17 
cncc: warning: -lm: 'linker' input unused [-Wunused-command-line-argument]
[2/2] c++ main.o bang.mlu.o -shared -lcnrt -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch/lib -lc10 -ltorch_cpu -ltorch_mlu -ltorch_mlu_python -lbangc -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/lib -ltorch -ltorch_python -L/usr/local/neuware/lib64 -L/usr/local/neuware/lib64 -o LeakyReLU.so
Ref time     : 27.769 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 1.4647841453552246e-05, "torch_us": 27.769, "bangc_us": 2314.3086582422256, "score": 0.011998831660203543}

[run 2]
ninja: no work to do.
Ref time     : 27.769 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 1.4647841453552246e-05, "torch_us": 27.769, "bangc_us": 2246.498130261898, "score": 0.012361016297290518}

[run 3]
ninja: no work to do.
Ref time     : 27.769 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 1.4647841453552246e-05, "torch_us": 27.769, "bangc_us": 2361.5295067429543, "score": 0.011758904523830951}

=== stderr ===
[run 1]
Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/torch_extensions/py310_cpu/LeakyReLU/build.ninja...
/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/mlu/__init__.py:379: UserWarning: Linear memory is not supported on this device. Falling back to common memory. (Triggered internally at /torch_mlu/torch_mlu/csrc/framework/core/caching_allocator.cpp:718.)
  torch_mlu._MLUC._mlu_init()
Building extension module LeakyReLU...
Allowing ninja to set a default number of workers... (overridable by setting the environment variable MAX_JOBS=N)
Loading extension module LeakyReLU...

[run 2]
Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/torch_extensions/py310_cpu/LeakyReLU/build.ninja...
/torch/venv3
002_matrix_scalar_multiplication — 得分: 0.334 | PASS (diff=1.59e-03)
输出:

=== stdout ===
[run 1]
[1/2] /usr/local/neuware/bin/cncc -c /root/.cache/torch_extensions/py310_cpu/matrix_scalar_multiplication/bang.mlu -o bang.mlu.o -DTORCH_EXTENSION_NAME=matrix_scalar_multiplication -DTORCH_API_INCLUDE_EXTENSION_H -DPYBIND11_COMPILER_TYPE=\"_gcc\" -DPYBIND11_STDLIB=\"_libstdcpp\" -DPYBIND11_BUILD_ABI=\"_cxxabi1011\" -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/torch/csrc/api/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/TH -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/THC -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/api/include/torch_mlu -isystem /usr/local/neuware/include -isystem /opt/py3.10/include/python3.10 -D_GLIBCXX_USE_CXX11_ABI=0 --bang-arch=compute_30 --no-neuware-version-check -fPIC -O3 -lm --neuware-path=/usr/local/neuware -std=c++17 
cncc: warning: -lm: 'linker' input unused [-Wunused-command-line-argument]
[2/2] c++ main.o bang.mlu.o -shared -lcnrt -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch/lib -lc10 -ltorch_cpu -ltorch_mlu -ltorch_mlu_python -lbangc -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/lib -ltorch -ltorch_python -L/usr/local/neuware/lib64 -L/usr/local/neuware/lib64 -o matrix_scalar_multiplication.so
Ref time     : 8274.871 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.0015916824340820312, "torch_us": 8274.871, "bangc_us": 24543.44928264618, "score": 0.3371519180008196}

[run 2]
ninja: no work to do.
Ref time     : 8274.871 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.0015916824340820312, "torch_us": 8274.871, "bangc_us": 24750.89393556118, "score": 0.33432614682700273}

[run 3]
ninja: no work to do.
Ref time     : 8274.871 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.0015916824340820312, "torch_us": 8274.871, "bangc_us": 25138.42936605215, "score": 0.32917215628334706}

=== stderr ===
[run 1]
Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/torch_extensions/py310_cpu/matrix_scalar_multiplication/build.ninja...
/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/mlu/__init__.py:379: UserWarning: Linear memory is not supported on this device. Falling back to common memory. (Triggered internally at /torch_mlu/torch_mlu/csrc/framework/core/caching_allocator.cpp:718.)
  torch_mlu._MLUC._mlu_init()
Building extension module matrix_scalar_multiplication...
Allowing ninja to set a default number of workers... (overridable by setting the environment variable MAX_JOBS=N)
Loading extension module matrix_scalar_multiplication...

[run 2]
Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, pat
003_LogSoftmax — 得分: 0.000 | PASS (diff=3.91e-03)
输出:

=== stdout ===
[run 1]
[1/2] /usr/local/neuware/bin/cncc -c /root/.cache/torch_extensions/py310_cpu/LogSoftmax/bang.mlu -o bang.mlu.o -DTORCH_EXTENSION_NAME=LogSoftmax -DTORCH_API_INCLUDE_EXTENSION_H -DPYBIND11_COMPILER_TYPE=\"_gcc\" -DPYBIND11_STDLIB=\"_libstdcpp\" -DPYBIND11_BUILD_ABI=\"_cxxabi1011\" -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/torch/csrc/api/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/TH -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/THC -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/api/include/torch_mlu -isystem /usr/local/neuware/include -isystem /opt/py3.10/include/python3.10 -D_GLIBCXX_USE_CXX11_ABI=0 --bang-arch=compute_30 --no-neuware-version-check -fPIC -O3 -lm --neuware-path=/usr/local/neuware -std=c++17 
cncc: warning: -lm: 'linker' input unused [-Wunused-command-line-argument]
[2/2] c++ main.o bang.mlu.o -shared -lcnrt -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch/lib -lc10 -ltorch_cpu -ltorch_mlu -ltorch_mlu_python -lbangc -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/lib -ltorch -ltorch_python -L/usr/local/neuware/lib64 -L/usr/local/neuware/lib64 -o LogSoftmax.so
Ref time     : 35.947 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.00390625, "torch_us": 35.947, "bangc_us": 96192.72500276566, "score": 0.00037369769906161283}

[run 2]
ninja: no work to do.
Ref time     : 35.947 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.003910064697265625, "torch_us": 35.947, "bangc_us": 96250.93173235655, "score": 0.00037347170934362757}

[run 3]
ninja: no work to do.
Ref time     : 35.947 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.00390625, "torch_us": 35.947, "bangc_us": 96114.78913575411, "score": 0.0003740007164685954}

=== stderr ===
[run 1]
Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/torch_extensions/py310_cpu/LogSoftmax/build.ninja...
/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/mlu/__init__.py:379: UserWarning: Linear memory is not supported on this device. Falling back to common memory. (Triggered internally at /torch_mlu/torch_mlu/csrc/framework/core/caching_allocator.cpp:718.)
  torch_mlu._MLUC._mlu_init()
Building extension module LogSoftmax...
Allowing ninja to set a default number of workers... (overridable by setting the environment variable MAX_JOBS=N)
Loading extension module LogSoftmax...

[run 2]
Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/torch_extensions/py310_cpu/LogSoftmax/build.ninja...
/torch/venv3/pytorch/lib/pyt
004_batched_matrix_multiplication — 得分: 0.000 | —
错误:

源码安全审计未通过 [FORBIDDEN_TORCH_HIGH_LEVEL_OP]：第 61 行命中规则，禁止直接调用 torch:: / at:: 下的现成算子实现，例如 at::conv(...)、torch::conv(...)。 片段: return at::bmm(A, B);
005_average_pooling_2d — 得分: 0.001 | PASS (diff=2.42e-04)
输出:

=== stdout ===
[run 1]
[1/2] /usr/local/neuware/bin/cncc -c /root/.cache/torch_extensions/py310_cpu/average_pooling_2d/bang.mlu -o bang.mlu.o -DTORCH_EXTENSION_NAME=average_pooling_2d -DTORCH_API_INCLUDE_EXTENSION_H -DPYBIND11_COMPILER_TYPE=\"_gcc\" -DPYBIND11_STDLIB=\"_libstdcpp\" -DPYBIND11_BUILD_ABI=\"_cxxabi1011\" -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/torch/csrc/api/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/TH -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/THC -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/api/include/torch_mlu -isystem /usr/local/neuware/include -isystem /opt/py3.10/include/python3.10 -D_GLIBCXX_USE_CXX11_ABI=0 --bang-arch=compute_30 --no-neuware-version-check -fPIC -O3 -lm --neuware-path=/usr/local/neuware -std=c++17 
cncc: warning: -lm: 'linker' input unused [-Wunused-command-line-argument]
[2/2] c++ main.o bang.mlu.o -shared -lcnrt -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch/lib -lc10 -ltorch_cpu -ltorch_mlu -ltorch_mlu_python -lbangc -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/lib -ltorch -ltorch_python -L/usr/local/neuware/lib64 -L/usr/local/neuware/lib64 -o average_pooling_2d.so
Ref time     : 7291.036 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.0002421736717224121, "torch_us": 7291.036, "bangc_us": 6767625.452950597, "score": 0.0010773403538195518}

[run 2]
ninja: no work to do.
Ref time     : 7291.036 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.0002421736717224121, "torch_us": 7291.036, "bangc_us": 6776338.50928396, "score": 0.001075955103188968}

[run 3]
ninja: no work to do.
Ref time     : 7291.036 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.0002421736717224121, "torch_us": 7291.036, "bangc_us": 6768280.06003052, "score": 0.0010772361567980275}

=== stderr ===
[run 1]
Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/torch_extensions/py310_cpu/average_pooling_2d/build.ninja...
/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/mlu/__init__.py:379: UserWarning: Linear memory is not supported on this device. Falling back to common memory. (Triggered internally at /torch_mlu/torch_mlu/csrc/framework/core/caching_allocator.cpp:718.)
  torch_mlu._MLUC._mlu_init()
Building extension module average_pooling_2d...
Allowing ninja to set a default number of workers... (overridable by setting the environment variable MAX_JOBS=N)
Loading extension module average_pooling_2d...

[run 2]
Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/tor
009_conv_standard_1D — 得分: 0.000 | PASS (diff=7.62e-03)
输出:

=== stdout ===
[run 1]
[1/2] /usr/local/neuware/bin/cncc -c /root/.cache/torch_extensions/py310_cpu/conv_standard_1d/bang.mlu -o bang.mlu.o -DTORCH_EXTENSION_NAME=conv_standard_1d -DTORCH_API_INCLUDE_EXTENSION_H -DPYBIND11_COMPILER_TYPE=\"_gcc\" -DPYBIND11_STDLIB=\"_libstdcpp\" -DPYBIND11_BUILD_ABI=\"_cxxabi1011\" -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/torch/csrc/api/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/TH -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/THC -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/api/include/torch_mlu -isystem /usr/local/neuware/include -isystem /opt/py3.10/include/python3.10 -D_GLIBCXX_USE_CXX11_ABI=0 --bang-arch=compute_30 --no-neuware-version-check -fPIC -O3 -lm --neuware-path=/usr/local/neuware -std=c++17 
cncc: warning: -lm: 'linker' input unused [-Wunused-command-line-argument]
[2/2] c++ main.o bang.mlu.o -shared -lcnrt -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch/lib -lc10 -ltorch_cpu -ltorch_mlu -ltorch_mlu_python -lbangc -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/lib -ltorch -ltorch_python -L/usr/local/neuware/lib64 -L/usr/local/neuware/lib64 -o conv_standard_1d.so
[2026-06-12 16:02:36.850585][CNNL][WARNING][915635][Card:0]: [cnnlGetConvolutionForwardAlgorithm] is deprecated and will be removed in the future release. See cnnlFindConvolutionForwardAlgo() API for replacement.
Ref time     : 71.834 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.006847381591796875, "torch_us": 71.834, "bangc_us": 500981.3867509365, "score": 0.00014338656465037963}

[run 2]
ninja: no work to do.
[2026-06-12 16:02:40.534354][CNNL][WARNING][916163][Card:0]: [cnnlGetConvolutionForwardAlgorithm] is deprecated and will be removed in the future release. See cnnlFindConvolutionForwardAlgo() API for replacement.
Ref time     : 71.834 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.0068607330322265625, "torch_us": 71.834, "bangc_us": 501751.3297498226, "score": 0.0001431665363713476}

[run 3]
ninja: no work to do.
[2026-06-12 16:02:44.85341][CNNL][WARNING][916251][Card:0]: [cnnlGetConvolutionForwardAlgorithm] is deprecated and will be removed in the future release. See cnnlFindConvolutionForwardAlgo() API for replacement.
Ref time     : 71.834 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.007617950439453125, "torch_us": 71.834, "bangc_us": 503553.37373912334, "score": 0.00014265419267593896}

=== stderr ===
[run 1]
Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/torch_extensions/py310_cpu/conv_standard_1d/build.ninja...
/torch/venv3/pytorch/lib/python3.10/site-packag
012_conv_transposed_2D__asymmetric_input__square_kernel — 得分: 0.000 | —
错误:

源码安全审计未通过 [FORBIDDEN_TORCH_HIGH_LEVEL_OP]：第 97 行命中规则，禁止直接调用 torch:: / at:: 下的现成算子实现，例如 at::conv(...)、torch::conv(...)。 片段: return at::conv_transpose2d(
023_Matrix_vector_multiplication_ — 得分: 0.000 | FAIL (diff=3.56e-01)
输出:

=== stdout ===
[run 1]
[1/2] /usr/local/neuware/bin/cncc -c /root/.cache/torch_extensions/py310_cpu/Matrix_vector_multiplication_/bang.mlu -o bang.mlu.o -DTORCH_EXTENSION_NAME=Matrix_vector_multiplication_ -DTORCH_API_INCLUDE_EXTENSION_H -DPYBIND11_COMPILER_TYPE=\"_gcc\" -DPYBIND11_STDLIB=\"_libstdcpp\" -DPYBIND11_BUILD_ABI=\"_cxxabi1011\" -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/torch/csrc/api/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/TH -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/THC -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/api/include/torch_mlu -isystem /usr/local/neuware/include -isystem /opt/py3.10/include/python3.10 -D_GLIBCXX_USE_CXX11_ABI=0 --bang-arch=compute_30 --no-neuware-version-check -fPIC -O3 -lm --neuware-path=/usr/local/neuware -std=c++17 
cncc: warning: -lm: 'linker' input unused [-Wunused-command-line-argument]
[2/2] c++ main.o bang.mlu.o -shared -lcnrt -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch/lib -lc10 -ltorch_cpu -ltorch_mlu -ltorch_mlu_python -lbangc -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/lib -ltorch -ltorch_python -L/usr/local/neuware/lib64 -L/usr/local/neuware/lib64 -o Matrix_vector_multiplication_.so
Ref time     : 953.936 us (from ref_times.json)
@@RESULT@@{"passed": false, "max_abs_diff": 0.2481689453125, "torch_us": 953.936, "bangc_us": 178702.40565389395, "score": 0.0}

[run 2]
ninja: no work to do.
Ref time     : 953.936 us (from ref_times.json)
@@RESULT@@{"passed": false, "max_abs_diff": 0.2481689453125, "torch_us": 953.936, "bangc_us": 178457.55442976952, "score": 0.0}

[run 3]
ninja: no work to do.
Ref time     : 953.936 us (from ref_times.json)
@@RESULT@@{"passed": false, "max_abs_diff": 0.3558349609375, "torch_us": 953.936, "bangc_us": 178448.79906624556, "score": 0.0}

=== stderr ===
[run 1]
Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/torch_extensions/py310_cpu/Matrix_vector_multiplication_/build.ninja...
/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/mlu/__init__.py:379: UserWarning: Linear memory is not supported on this device. Falling back to common memory. (Triggered internally at /torch_mlu/torch_mlu/csrc/framework/core/caching_allocator.cpp:718.)
  torch_mlu._MLUC._mlu_init()
Building extension module Matrix_vector_multiplication_...
Allowing ninja to set a default number of workers... (overridable by setting the environment variable MAX_JOBS=N)
Loading extension module Matrix_vector_multiplication_...

[run 2]
Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/torch_
034_Argmax_over_a_dimension — 得分: 0.000 | PASS (diff=0.00e+00)
输出:

=== stdout ===
[run 1]
[1/2] /usr/local/neuware/bin/cncc -c /root/.cache/torch_extensions/py310_cpu/Argmax_over_a_dimension/bang.mlu -o bang.mlu.o -DTORCH_EXTENSION_NAME=Argmax_over_a_dimension -DTORCH_API_INCLUDE_EXTENSION_H -DPYBIND11_COMPILER_TYPE=\"_gcc\" -DPYBIND11_STDLIB=\"_libstdcpp\" -DPYBIND11_BUILD_ABI=\"_cxxabi1011\" -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/torch/csrc/api/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/TH -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/THC -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/api/include/torch_mlu -isystem /usr/local/neuware/include -isystem /opt/py3.10/include/python3.10 -D_GLIBCXX_USE_CXX11_ABI=0 --bang-arch=compute_30 --no-neuware-version-check -fPIC -O3 -lm --neuware-path=/usr/local/neuware -std=c++17 
cncc: warning: -lm: 'linker' input unused [-Wunused-command-line-argument]
[2/2] c++ main.o bang.mlu.o -shared -lcnrt -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch/lib -lc10 -ltorch_cpu -ltorch_mlu -ltorch_mlu_python -lbangc -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/lib -ltorch -ltorch_python -L/usr/local/neuware/lib64 -L/usr/local/neuware/lib64 -o Argmax_over_a_dimension.so
Ref time     : 43.970 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.0, "torch_us": 43.97, "bangc_us": 101099.66062009335, "score": 0.00043491738478952966}

[run 2]
ninja: no work to do.
Ref time     : 43.970 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.0, "torch_us": 43.97, "bangc_us": 102655.2515104413, "score": 0.0004283268449790677}

[run 3]
ninja: no work to do.
Ref time     : 43.970 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.0, "torch_us": 43.97, "bangc_us": 101227.00594365597, "score": 0.00043437025120029896}

=== stderr ===
[run 1]
Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/torch_extensions/py310_cpu/Argmax_over_a_dimension/build.ninja...
/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/mlu/__init__.py:379: UserWarning: Linear memory is not supported on this device. Falling back to common memory. (Triggered internally at /torch_mlu/torch_mlu/csrc/framework/core/caching_allocator.cpp:718.)
  torch_mlu._MLUC._mlu_init()
Building extension module Argmax_over_a_dimension...
Allowing ninja to set a default number of workers... (overridable by setting the environment variable MAX_JOBS=N)
Loading extension module Argmax_over_a_dimension...

[run 2]
Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/torch_extensions/py310_cpu/Argmax_o
039_BatchNorm — 得分: 0.000 | PASS (diff=1.00e-03)
输出:

=== stdout ===
[run 1]
[1/2] /usr/local/neuware/bin/cncc -c /root/.cache/torch_extensions/py310_cpu/BatchNorm/bang.mlu -o bang.mlu.o -DTORCH_EXTENSION_NAME=BatchNorm -DTORCH_API_INCLUDE_EXTENSION_H -DPYBIND11_COMPILER_TYPE=\"_gcc\" -DPYBIND11_STDLIB=\"_libstdcpp\" -DPYBIND11_BUILD_ABI=\"_cxxabi1011\" -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/torch/csrc/api/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/TH -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/THC -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/api/include/torch_mlu -isystem /usr/local/neuware/include -isystem /opt/py3.10/include/python3.10 -D_GLIBCXX_USE_CXX11_ABI=0 --bang-arch=compute_30 --no-neuware-version-check -fPIC -O3 -lm --neuware-path=/usr/local/neuware -std=c++17 
cncc: warning: -lm: 'linker' input unused [-Wunused-command-line-argument]
[2/2] c++ main.o bang.mlu.o -shared -lcnrt -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch/lib -lc10 -ltorch_cpu -ltorch_mlu -ltorch_mlu_python -lbangc -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/lib -ltorch -ltorch_python -L/usr/local/neuware/lib64 -L/usr/local/neuware/lib64 -o BatchNorm.so
Ref time     : 5349.541 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.000982522964477539, "torch_us": 5349.541, "bangc_us": 20294650.04708618, "score": 0.00026359365584468727}

[run 2]
ninja: no work to do.
Ref time     : 5349.541 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.0009822845458984375, "torch_us": 5349.541, "bangc_us": 20836469.628848135, "score": 0.0002567393179021819}

[run 3]
ninja: no work to do.
Ref time     : 5349.541 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.0010006427764892578, "torch_us": 5349.541, "bangc_us": 20817334.72365886, "score": 0.0002569753078870494}

=== stderr ===
[run 1]
Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/torch_extensions/py310_cpu/BatchNorm/build.ninja...
/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/mlu/__init__.py:379: UserWarning: Linear memory is not supported on this device. Falling back to common memory. (Triggered internally at /torch_mlu/torch_mlu/csrc/framework/core/caching_allocator.cpp:718.)
  torch_mlu._MLUC._mlu_init()
Building extension module BatchNorm...
Allowing ninja to set a default number of workers... (overridable by setting the environment variable MAX_JOBS=N)
Loading extension module BatchNorm...

[run 2]
Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/torch_extensions/py310_cpu/BatchNorm/build.ninja...
/
051_cumsum — 得分: 0.000 | PASS (diff=4.58e-05)
输出:

=== stdout ===
[run 1]
[1/2] /usr/local/neuware/bin/cncc -c /root/.cache/torch_extensions/py310_cpu/cumsum/bang.mlu -o bang.mlu.o -DTORCH_EXTENSION_NAME=cumsum -DTORCH_API_INCLUDE_EXTENSION_H -DPYBIND11_COMPILER_TYPE=\"_gcc\" -DPYBIND11_STDLIB=\"_libstdcpp\" -DPYBIND11_BUILD_ABI=\"_cxxabi1011\" -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/torch/csrc/api/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/TH -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/THC -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/api/include/torch_mlu -isystem /usr/local/neuware/include -isystem /opt/py3.10/include/python3.10 -D_GLIBCXX_USE_CXX11_ABI=0 --bang-arch=compute_30 --no-neuware-version-check -fPIC -O3 -lm --neuware-path=/usr/local/neuware -std=c++17 
cncc: warning: -lm: 'linker' input unused [-Wunused-command-line-argument]
[2/2] c++ main.o bang.mlu.o -shared -lcnrt -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch/lib -lc10 -ltorch_cpu -ltorch_mlu -ltorch_mlu_python -lbangc -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/lib -ltorch -ltorch_python -L/usr/local/neuware/lib64 -L/usr/local/neuware/lib64 -o cumsum.so
Ref time     : 47.620 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 3.0517578125e-05, "torch_us": 47.62, "bangc_us": 95949.936658144, "score": 0.0004963004839665846}

[run 2]
ninja: no work to do.
Ref time     : 47.620 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 3.0517578125e-05, "torch_us": 47.62, "bangc_us": 96294.68899220228, "score": 0.0004945236388255654}

[run 3]
ninja: no work to do.
Ref time     : 47.620 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 4.57763671875e-05, "torch_us": 47.62, "bangc_us": 96325.37420839071, "score": 0.0004943661043763888}

=== stderr ===
[run 1]
Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/torch_extensions/py310_cpu/cumsum/build.ninja...
/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/mlu/__init__.py:379: UserWarning: Linear memory is not supported on this device. Falling back to common memory. (Triggered internally at /torch_mlu/torch_mlu/csrc/framework/core/caching_allocator.cpp:718.)
  torch_mlu._MLUC._mlu_init()
Building extension module cumsum...
Allowing ninja to set a default number of workers... (overridable by setting the environment variable MAX_JOBS=N)
Loading extension module cumsum...

[run 2]
Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/torch_extensions/py310_cpu/cumsum/build.ninja...
/torch/venv3/pytorch/lib/python3.10/site-packages/torc
056_gather — 得分: 0.000 | FAIL (diff=2.48e+01)
输出:

=== stdout ===
[run 1]
[1/2] /usr/local/neuware/bin/cncc -c /root/.cache/torch_extensions/py310_cpu/gather/bang.mlu -o bang.mlu.o -DTORCH_EXTENSION_NAME=gather -DTORCH_API_INCLUDE_EXTENSION_H -DPYBIND11_COMPILER_TYPE=\"_gcc\" -DPYBIND11_STDLIB=\"_libstdcpp\" -DPYBIND11_BUILD_ABI=\"_cxxabi1011\" -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/torch/csrc/api/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/TH -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/THC -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/api/include/torch_mlu -isystem /usr/local/neuware/include -isystem /opt/py3.10/include/python3.10 -D_GLIBCXX_USE_CXX11_ABI=0 --bang-arch=compute_30 --no-neuware-version-check -fPIC -O3 -lm --neuware-path=/usr/local/neuware -std=c++17 
cncc: warning: -lm: 'linker' input unused [-Wunused-command-line-argument]
[2/2] c++ main.o bang.mlu.o -shared -lcnrt -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch/lib -lc10 -ltorch_cpu -ltorch_mlu -ltorch_mlu_python -lbangc -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/lib -ltorch -ltorch_python -L/usr/local/neuware/lib64 -L/usr/local/neuware/lib64 -o gather.so
[2026-06-12 16:06:50.526149][CNNL][WARNING][919341][Card:0]: [cnnlFill_v3] is deprecated and will be removed in the future release, Use [cnnlFill_v4] instead.
Ref time     : 269.403 us (from ref_times.json)
@@RESULT@@{"passed": false, "max_abs_diff": 24.7841796875, "torch_us": 269.403, "bangc_us": 4579.352214932442, "score": 0.0}

[run 2]
ninja: no work to do.
[2026-06-12 16:06:53.822600][CNNL][WARNING][919755][Card:0]: [cnnlFill_v3] is deprecated and will be removed in the future release, Use [cnnlFill_v4] instead.
Ref time     : 269.403 us (from ref_times.json)
@@RESULT@@{"passed": false, "max_abs_diff": 24.7841796875, "torch_us": 269.403, "bangc_us": 4491.773433983326, "score": 0.0}

[run 3]
ninja: no work to do.
[2026-06-12 16:07:00.96786][CNNL][WARNING][919900][Card:0]: [cnnlFill_v3] is deprecated and will be removed in the future release, Use [cnnlFill_v4] instead.
Ref time     : 269.403 us (from ref_times.json)
@@RESULT@@{"passed": false, "max_abs_diff": 24.7841796875, "torch_us": 269.403, "bangc_us": 4263.483919203281, "score": 0.0}

=== stderr ===
[run 1]
Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/torch_extensions/py310_cpu/gather/build.ninja...
/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/mlu/__init__.py:379: UserWarning: Linear memory is not supported on this device. Falling back to common memory. (Triggered internally at /torch_mlu/torch_mlu/csrc/framework/core/caching_allocator.cpp:718.)
  torch_mlu._MLUC._mlu_init()
Building extension modu
070_Sqrt — 得分: 0.018 | PASS (diff=4.88e-04)
输出:

=== stdout ===
[run 1]
[1/2] /usr/local/neuware/bin/cncc -c /root/.cache/torch_extensions/py310_cpu/Sqrt/bang.mlu -o bang.mlu.o -DTORCH_EXTENSION_NAME=Sqrt -DTORCH_API_INCLUDE_EXTENSION_H -DPYBIND11_COMPILER_TYPE=\"_gcc\" -DPYBIND11_STDLIB=\"_libstdcpp\" -DPYBIND11_BUILD_ABI=\"_cxxabi1011\" -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/torch/csrc/api/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/TH -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/THC -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/api/include/torch_mlu -isystem /usr/local/neuware/include -isystem /opt/py3.10/include/python3.10 -D_GLIBCXX_USE_CXX11_ABI=0 --bang-arch=compute_30 --no-neuware-version-check -fPIC -O3 -lm --neuware-path=/usr/local/neuware -std=c++17 
cncc: warning: -lm: 'linker' input unused [-Wunused-command-line-argument]
[2/2] c++ main.o bang.mlu.o -shared -lcnrt -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch/lib -lc10 -ltorch_cpu -ltorch_mlu -ltorch_mlu_python -lbangc -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/lib -ltorch -ltorch_python -L/usr/local/neuware/lib64 -L/usr/local/neuware/lib64 -o Sqrt.so
Ref time     : 39.894 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.0004881620407104492, "torch_us": 39.894, "bangc_us": 2089.3029868602753, "score": 0.019094406244999047}

[run 2]
ninja: no work to do.
Ref time     : 39.894 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.0004881620407104492, "torch_us": 39.894, "bangc_us": 2221.8944504857063, "score": 0.0179549483060634}

[run 3]
ninja: no work to do.
Ref time     : 39.894 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.0004881620407104492, "torch_us": 39.894, "bangc_us": 2347.5661873817444, "score": 0.016993770064687306}

=== stderr ===
[run 1]
Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/torch_extensions/py310_cpu/Sqrt/build.ninja...
/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/mlu/__init__.py:379: UserWarning: Linear memory is not supported on this device. Falling back to common memory. (Triggered internally at /torch_mlu/torch_mlu/csrc/framework/core/caching_allocator.cpp:718.)
  torch_mlu._MLUC._mlu_init()
Building extension module Sqrt...
Allowing ninja to set a default number of workers... (overridable by setting the environment variable MAX_JOBS=N)
Loading extension module Sqrt...

[run 2]
Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/torch_extensions/py310_cpu/Sqrt/build.ninja...
/torch/venv3/pytorch/lib/python3.10/site-packages/t
075_TopK — 得分: 0.000 | PASS (diff=0.00e+00)
输出:

=== stdout ===
[run 1]
[1/2] /usr/local/neuware/bin/cncc -c /root/.cache/torch_extensions/py310_cpu/TopK/bang.mlu -o bang.mlu.o -DTORCH_EXTENSION_NAME=TopK -DTORCH_API_INCLUDE_EXTENSION_H -DPYBIND11_COMPILER_TYPE=\"_gcc\" -DPYBIND11_STDLIB=\"_libstdcpp\" -DPYBIND11_BUILD_ABI=\"_cxxabi1011\" -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/torch/csrc/api/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/TH -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/THC -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/api/include/torch_mlu -isystem /usr/local/neuware/include -isystem /opt/py3.10/include/python3.10 -D_GLIBCXX_USE_CXX11_ABI=0 --bang-arch=compute_30 --no-neuware-version-check -fPIC -O3 -lm --neuware-path=/usr/local/neuware -std=c++17 
cncc: warning: -lm: 'linker' input unused [-Wunused-command-line-argument]
[2/2] c++ main.o bang.mlu.o -shared -lcnrt -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch/lib -lc10 -ltorch_cpu -ltorch_mlu -ltorch_mlu_python -lbangc -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/lib -ltorch -ltorch_python -L/usr/local/neuware/lib64 -L/usr/local/neuware/lib64 -o TopK.so
Ref time     : 28.688 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.0, "torch_us": 28.688, "bangc_us": 72011.48755848408, "score": 0.0003983808830042715}

[run 2]
ninja: no work to do.
Ref time     : 28.688 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.0, "torch_us": 28.688, "bangc_us": 72187.933139503, "score": 0.00039740713928684607}

[run 3]
ninja: no work to do.
Ref time     : 28.688 us (from ref_times.json)
@@RESULT@@{"passed": true, "max_abs_diff": 0.0, "torch_us": 28.688, "bangc_us": 72217.87143498659, "score": 0.0003972423920833236}

=== stderr ===
[run 1]
Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/torch_extensions/py310_cpu/TopK/build.ninja...
/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/mlu/__init__.py:379: UserWarning: Linear memory is not supported on this device. Falling back to common memory. (Triggered internally at /torch_mlu/torch_mlu/csrc/framework/core/caching_allocator.cpp:718.)
  torch_mlu._MLUC._mlu_init()
Building extension module TopK...
Allowing ninja to set a default number of workers... (overridable by setting the environment variable MAX_JOBS=N)
Loading extension module TopK...

[run 2]
Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/torch_extensions/py310_cpu/TopK/build.ninja...
/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/mlu/__init__.py:379: UserWarning: Linear mem
103_MSE_Loss — 得分: 0.000 | —
错误:

源码安全审计未通过 [FORBIDDEN_TORCH_HIGH_LEVEL_OP]：第 33 行命中规则，禁止直接调用 torch:: / at:: 下的现成算子实现，例如 at::conv(...)、torch::conv(...)。 片段: return at::mse_loss(predictions, targets, at::Reduction::Mean);
104_KL_Divergence_Loss — 得分: 0.000 | —
错误:

源码安全审计未通过 [FORBIDDEN_TORCH_MODULE_API]：第 50 行命中规则，禁止直接使用高层 torch 模块 API：torch::nn:: / torch::jit:: / torch::autograd:: / torch::optim::。 片段: namespace F = torch::nn::functional;
109_Scatter_add — 得分: 0.000 | —
错误:

源码安全审计未通过 [FORBIDDEN_TORCH_HIGH_LEVEL_OP]：第 64 行命中规则，禁止直接调用 torch:: / at:: 下的现成算子实现，例如 at::conv(...)、torch::conv(...)。 片段: return at::index_add(output, 0, index_i64, src);
111_Masked_select — 得分: 0.000 | —
错误:

源码安全审计未通过 [FORBIDDEN_TORCH_HIGH_LEVEL_OP]：第 12 行命中规则，禁止直接调用 torch:: / at:: 下的现成算子实现，例如 at::conv(...)、torch::conv(...)。 片段: return at::masked_select(input, mask);
135_Dilated_conv_2D — 得分: 0.000 | —
错误:

源码安全审计未通过 [FORBIDDEN_TORCH_HIGH_LEVEL_OP]：第 73 行命中规则，禁止直接调用 torch:: / at:: 下的现成算子实现，例如 at::conv(...)、torch::conv(...)。 片段: return at::conv2d(
138_GRU_forward — 得分: 0.000 | —
错误:

run 1: BangC 编译错误: Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/torch_extensions/py310_cpu/GRU_forward/build.ninja...
/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/mlu/__init__.py:379: UserWarning: Linear memory is not supported on this device. Falling back to common memory. (Triggered internally at /torch_mlu/torch_mlu/csrc/framework/core/caching_allocator.cpp:718.)
  torch_mlu._MLUC._mlu_init()
Building extension module GRU_forward...
Allowing ninja to set a default number of workers... (overridable by setting the environment variable MAX_JOBS=N)
Loading extension module GRU_forward...
[COMPILE ERROR] BangC 模型加载/编译失败: /data/workspace/87_eval_9e982bb77cd8/138_GRU_forward_mlu.py
错误类型: ImportError
错误信息: /root/.cache/torch_extensions/py310_cpu/GRU_forward/GRU_forward.so: undefined symbol: _Z9bang_funcN2at6TensorES0_S0_S0_S0_S0_S0_S0_S0_iii

Traceback (most recent call last):
  File "/workspace/volume/d1/bangc_torch_tester.py", line 288, in run
    bangc_mod = load_module("bangc_model", bangc_model_path)
  File "/workspace/volume/d1/bangc_torch_tester.py", line 52, in load_module
    spec.loader.exec_module(module)
  File "<frozen importlib._bootstrap_external>", line 883, in exec_module
  File "<frozen importlib._bootstrap>", line 241, in _call_with_frames_removed
  File "/data/workspace/87_eval_9e982bb77cd8/138_GRU_forward_mlu.py", line 27, in <module>
    bang_func_ext = load_inline(
  File "/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/utils/cpp_extension.py", line 481, in load_inline
    return _jit_compile(
  File "/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/utils/cpp_extension.py", line 544, in _jit_compile
    return torch.utils.cpp_extension._import_module_from_library(
  File "/torch/venv3/pytorch/lib/python3.10/site-packages/torch/utils/cpp_extension.py", line 2140, in _import_module_from_library
    module = importlib.util.module_from_spec(spec)
  File "<frozen importlib._bootstrap>", line 571, in module_from_spec
  File "<frozen importlib._bootstrap_external>", line 1176, in create_module
  File "<frozen importlib._bootstrap>", line 241, in _call_with_frames_removed
ImportError: /root/.cache/torch_extensions/py310_cpu/GRU_forward/GRU_forward.so: undefined symbol: _Z9bang_funcN2at6TensorES0_S0_S0_S0_S0_S0_S0_S0_iii | run 2: BangC 编译错误: Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/torch_extensions/py310_cpu/GRU_forward/build.ninja...
/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/mlu/__init__.py:379: UserWarning: Linear memory is not supported on this device. Falling back to common memory. (Triggered internally at /torch_mlu/torch_mlu/csrc/framework/core/caching_allocator.cpp:718.)
  torch_mlu._MLUC._mlu_init()
Building extension module GRU_forward...
Allowing ninja to set
输出:

=== stdout ===
[run 1]
[1/2] /usr/local/neuware/bin/cncc -c /root/.cache/torch_extensions/py310_cpu/GRU_forward/bang.mlu -o bang.mlu.o -DTORCH_EXTENSION_NAME=GRU_forward -DTORCH_API_INCLUDE_EXTENSION_H -DPYBIND11_COMPILER_TYPE=\"_gcc\" -DPYBIND11_STDLIB=\"_libstdcpp\" -DPYBIND11_BUILD_ABI=\"_cxxabi1011\" -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/torch/csrc/api/include -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/TH -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch/include/THC -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc -isystem /torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/api/include/torch_mlu -isystem /usr/local/neuware/include -isystem /opt/py3.10/include/python3.10 -D_GLIBCXX_USE_CXX11_ABI=0 --bang-arch=compute_30 --no-neuware-version-check -fPIC -O3 -lm --neuware-path=/usr/local/neuware -std=c++17 
cncc: warning: -lm: 'linker' input unused [-Wunused-command-line-argument]
[2/2] c++ main.o bang.mlu.o -shared -lcnrt -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch/lib -lc10 -ltorch_cpu -ltorch_mlu -ltorch_mlu_python -lbangc -L/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/csrc/lib -ltorch -ltorch_python -L/usr/local/neuware/lib64 -L/usr/local/neuware/lib64 -o GRU_forward.so

[run 2]
ninja: no work to do.

[run 3]
ninja: no work to do.

=== stderr ===
[run 1]
Using /root/.cache/torch_extensions/py310_cpu as PyTorch extensions root...
Detected MLU files, patching ldflags
Emitting ninja build file /root/.cache/torch_extensions/py310_cpu/GRU_forward/build.ninja...
/torch/venv3/pytorch/lib/python3.10/site-packages/torch_mlu/mlu/__init__.py:379: UserWarning: Linear memory is not supported on this device. Falling back to common memory. (Triggered internally at /torch_mlu/torch_mlu/csrc/framework/core/caching_allocator.cpp:718.)
  torch_mlu._MLUC._mlu_init()
Building extension module GRU_forward...
Allowing ninja to set a default number of workers... (overridable by setting the environment variable MAX_JOBS=N)
Loading extension module GRU_forward...
[COMPILE ERROR] BangC 模型加载/编译失败: /data/workspace/87_eval_9e982bb77cd8/138_GRU_forward_mlu.py
错误类型: ImportError
错误信息: /root/.cache/torch_extensions/py310_cpu/GRU_forward/GRU_forward.so: undefined symbol: _Z9bang_funcN2at6TensorES0_S0_S0_S0_S0_S0_S0_S0_iii

Traceback (most recent call last):
  File "/workspace/volume/d1/bangc_torch_tester.py", line 288, in run
    bangc_mod = load_module("bangc_model", bangc_model_path)
  File "/workspace/volume/d1/bangc_torch_tester.py", line 52, in load_module
    spec.loader.exec_module(module)
  File "<frozen importlib._bootstrap_external>", line 883, in exec_module
  File "<frozen importlib._bootstrap>", line 241, in _call_with_frames_removed
  File "/data/workspace/87_eval_9e982bb77cd8/138_GRU_forward_mlu.py", line 27, in <module>
    bang_func_ext = load
