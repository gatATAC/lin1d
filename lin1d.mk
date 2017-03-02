##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=lin1d
ConfigurationName      :=Debug
WorkspacePath          := "/home/est/dev/gatatac/arduino/lin1d"
ProjectPath            := "/home/est/dev/gatatac/arduino/lin1d"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=est
Date                   :=03/02/17
CodeLitePath           :="/home/est/.codelite"
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
Objects0=$(IntermediateDirectory)/maincl.cpp$(ObjectSuffix) $(IntermediateDirectory)/DRE.c$(ObjectSuffix) $(IntermediateDirectory)/DummyFunctions.c$(ObjectSuffix) $(IntermediateDirectory)/lin1dFSM.c$(ObjectSuffix) $(IntermediateDirectory)/lin1dFSM_CI.c$(ObjectSuffix) $(IntermediateDirectory)/ProjectFunctions.c$(ObjectSuffix) 



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
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/est/dev/gatatac/arduino/lin1d/maincl.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/maincl.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/maincl.cpp$(DependSuffix): maincl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/maincl.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/maincl.cpp$(DependSuffix) -MM "maincl.cpp"

$(IntermediateDirectory)/maincl.cpp$(PreprocessSuffix): maincl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/maincl.cpp$(PreprocessSuffix) "maincl.cpp"

$(IntermediateDirectory)/DRE.c$(ObjectSuffix): DRE.c $(IntermediateDirectory)/DRE.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/est/dev/gatatac/arduino/lin1d/DRE.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DRE.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DRE.c$(DependSuffix): DRE.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DRE.c$(ObjectSuffix) -MF$(IntermediateDirectory)/DRE.c$(DependSuffix) -MM "DRE.c"

$(IntermediateDirectory)/DRE.c$(PreprocessSuffix): DRE.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DRE.c$(PreprocessSuffix) "DRE.c"

$(IntermediateDirectory)/DummyFunctions.c$(ObjectSuffix): DummyFunctions.c $(IntermediateDirectory)/DummyFunctions.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/est/dev/gatatac/arduino/lin1d/DummyFunctions.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DummyFunctions.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DummyFunctions.c$(DependSuffix): DummyFunctions.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DummyFunctions.c$(ObjectSuffix) -MF$(IntermediateDirectory)/DummyFunctions.c$(DependSuffix) -MM "DummyFunctions.c"

$(IntermediateDirectory)/DummyFunctions.c$(PreprocessSuffix): DummyFunctions.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DummyFunctions.c$(PreprocessSuffix) "DummyFunctions.c"

$(IntermediateDirectory)/lin1dFSM.c$(ObjectSuffix): lin1dFSM.c $(IntermediateDirectory)/lin1dFSM.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/est/dev/gatatac/arduino/lin1d/lin1dFSM.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lin1dFSM.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lin1dFSM.c$(DependSuffix): lin1dFSM.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lin1dFSM.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lin1dFSM.c$(DependSuffix) -MM "lin1dFSM.c"

$(IntermediateDirectory)/lin1dFSM.c$(PreprocessSuffix): lin1dFSM.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lin1dFSM.c$(PreprocessSuffix) "lin1dFSM.c"

$(IntermediateDirectory)/lin1dFSM_CI.c$(ObjectSuffix): lin1dFSM_CI.c $(IntermediateDirectory)/lin1dFSM_CI.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/est/dev/gatatac/arduino/lin1d/lin1dFSM_CI.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lin1dFSM_CI.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lin1dFSM_CI.c$(DependSuffix): lin1dFSM_CI.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lin1dFSM_CI.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lin1dFSM_CI.c$(DependSuffix) -MM "lin1dFSM_CI.c"

$(IntermediateDirectory)/lin1dFSM_CI.c$(PreprocessSuffix): lin1dFSM_CI.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lin1dFSM_CI.c$(PreprocessSuffix) "lin1dFSM_CI.c"

$(IntermediateDirectory)/ProjectFunctions.c$(ObjectSuffix): ProjectFunctions.c $(IntermediateDirectory)/ProjectFunctions.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/est/dev/gatatac/arduino/lin1d/ProjectFunctions.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ProjectFunctions.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ProjectFunctions.c$(DependSuffix): ProjectFunctions.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ProjectFunctions.c$(ObjectSuffix) -MF$(IntermediateDirectory)/ProjectFunctions.c$(DependSuffix) -MM "ProjectFunctions.c"

$(IntermediateDirectory)/ProjectFunctions.c$(PreprocessSuffix): ProjectFunctions.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ProjectFunctions.c$(PreprocessSuffix) "ProjectFunctions.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) ".build-debug/lin1d"


