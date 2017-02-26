lib_LIBRARIES = libdataflow.a
libdataflow_a_SOURCES = DefaultPipeline.cpp
libdataflow_a_SOURCES += DefaultPipelineBuilder.cpp
libdataflow_a_SOURCES += PipelineManager.cpp


bin_PROGRAMS = dataflow

dataflow_SOURCES = main.cpp
dataflow_SOURCES += DefaultPipelineBuilder.cpp
dataflow_SOURCES += DefaultPipeline.cpp
dataflow_LDADD = libdataflow.a
