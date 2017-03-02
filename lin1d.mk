##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=lin1d
ConfigurationName      :=Debug
WorkspacePath          := "/home/pi/dev/lin1d"
ProjectPath            := "/home/pi/dev/lin1d"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=03/02/17
CodeLitePath           :="/home/pi/.codelite"
LinkerName             :=/usr/bin/g++ 
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)DUMMY_COMPILATION 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="lin1d.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++ 
CC       := /usr/bin/gcc 
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/maincl.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_DRE.c$(ObjectSuffix) $(IntermediateDirectory)/src_DummyFunctions.c$(ObjectSuffix) $(IntermediateDirectory)/src_ProjectFunctions.c$(ObjectSuffix) $(IntermediateDirectory)/src_lin1dFSM.c$(ObjectSuffix) $(IntermediateDirectory)/src_lin1dFSM_CI.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/maincl.cpp$(ObjectSuffix): maincl.cpp $(IntermediateDirectory)/maincl.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/pi/dev/lin1d/maincl.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/maincl.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/maincl.cpp$(DependSuffix): maincl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/maincl.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/maincl.cpp$(DependSuffix) -MM "maincl.cpp"

$(IntermediateDirectory)/maincl.cpp$(PreprocessSuffix): maincl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/maincl.cpp$(PreprocessSuffix) "maincl.cpp"

$(IntermediateDirectory)/src_DRE.c$(ObjectSuffix): src/DRE.c $(IntermediateDirectory)/src_DRE.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/pi/dev/lin1d/src/DRE.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_DRE.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_DRE.c$(DependSuffix): src/DRE.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_DRE.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_DRE.c$(DependSuffix) -MM "src/DRE.c"

$(IntermediateDirectory)/src_DRE.c$(PreprocessSuffix): src/DRE.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_DRE.c$(PreprocessSuffix) "src/DRE.c"

$(IntermediateDirectory)/src_DummyFunctions.c$(ObjectSuffix): src/DummyFunctions.c $(IntermediateDirectory)/src_DummyFunctions.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/pi/dev/lin1d/src/DummyFunctions.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_DummyFunctions.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_DummyFunctions.c$(DependSuffix): src/DummyFunctions.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_DummyFunctions.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_DummyFunctions.c$(DependSuffix) -MM "src/DummyFunctions.c"

$(IntermediateDirectory)/src_DummyFunctions.c$(PreprocessSuffix): src/DummyFunctions.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_DummyFunctions.c$(PreprocessSuffix) "src/DummyFunctions.c"

$(IntermediateDirectory)/src_ProjectFunctions.c$(ObjectSuffix): src/ProjectFunctions.c $(IntermediateDirectory)/src_ProjectFunctions.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/pi/dev/lin1d/src/ProjectFunctions.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ProjectFunctions.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ProjectFunctions.c$(DependSuffix): src/ProjectFunctions.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ProjectFunctions.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ProjectFunctions.c$(DependSuffix) -MM "src/ProjectFunctions.c"

$(IntermediateDirectory)/src_ProjectFunctions.c$(PreprocessSuffix): src/ProjectFunctions.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ProjectFunctions.c$(PreprocessSuffix) "src/ProjectFunctions.c"

$(IntermediateDirectory)/src_lin1dFSM.c$(ObjectSuffix): src/lin1dFSM.c $(IntermediateDirectory)/src_lin1dFSM.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/pi/dev/lin1d/src/lin1dFSM.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lin1dFSM.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lin1dFSM.c$(DependSuffix): src/lin1dFSM.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lin1dFSM.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lin1dFSM.c$(DependSuffix) -MM "src/lin1dFSM.c"

$(IntermediateDirectory)/src_lin1dFSM.c$(PreprocessSuffix): src/lin1dFSM.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lin1dFSM.c$(PreprocessSuffix) "src/lin1dFSM.c"

$(IntermediateDirectory)/src_lin1dFSM_CI.c$(ObjectSuffix): src/lin1dFSM_CI.c $(IntermediateDirectory)/src_lin1dFSM_CI.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/pi/dev/lin1d/src/lin1dFSM_CI.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_lin1dFSM_CI.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_lin1dFSM_CI.c$(DependSuffix): src/lin1dFSM_CI.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_lin1dFSM_CI.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_lin1dFSM_CI.c$(DependSuffix) -MM "src/lin1dFSM_CI.c"

$(IntermediateDirectory)/src_lin1dFSM_CI.c$(PreprocessSuffix): src/lin1dFSM_CI.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_lin1dFSM_CI.c$(PreprocessSuffix) "src/lin1dFSM_CI.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) ".build-debug/lin1d"


