#/*============================================================================
#
#  PHAS0100ASSIGNMENT2: PHAS0100 Assignment 2 Social Force Model
#
#  Copyright (c) University College London (UCL). All rights reserved.
#
#  This software is distributed WITHOUT ANY WARRANTY; without even
#  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
#  PURPOSE.
#
#  See LICENSE.txt in the top level directory for details.
#
#============================================================================*/

find_package(OpenMP)

set(_command_line_apps
  sfmPartASection4App
  sfmPartASection5App
  sfmPartBSection6dApp
  sfmPartBSection6eApp
  sfmPartBSection7aApp
  sfmPartBSection7b1App
  sfmPartBSection7b2App
  sfmPartBSection7b3App
)

foreach(_app ${_command_line_apps})
  add_executable(${_app} ${_app}.cpp)
  target_link_libraries(${_app} PUBLIC OpenMP::OpenMP_CXX ${PHAS0100ASSIGNMENT2_LIBRARIES} ${ALL_THIRD_PARTY_LIBRARIES})
endforeach()
