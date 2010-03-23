# rakefilb.rb - Used to build lemon
#
# Time-stamp: <Last modified 2010-03-22 20:32:56 by Eric Scrivner>
#
# Copyright (c) 2010 lemon team
#
# This software is provided 'as-is', without any express or implied
# warranty. In no event will the authors be held liable for any damages
# arising from the use of this software.
#
# Permission is granted to anyone to use this software for any purpose,
# including commercial applications, and to alter it and redistribute it
# freely, subject to the following restrictions:
#
# 1. The origin of this software must not be misrepresented; you must not
# claim that you wrote the original software. If you use this software
# in a product, an acknowledgment in the product documentation would be
# appreciated but is not required.
#
# 2. Altered source versions must be plainly marked as such, and must not be
# misrepresented as being the original software.
#
# 3. This notice may not be removed or altered from any source
# distribution.
require 'rake'
require 'rake/clean'

# Constants
RESULT   = 'tests/all_tests.out'
EXAMPLES = FileList['examples/*.cpp'].ext('out')

# Clean
CLEAN.include('*.o')
CLEAN.include('tests/*.o')
CLEAN.include(RESULT)
CLEAN.include(EXAMPLES)

# Rules
rule '.out' => '.cpp' do |t|
  sh "g++ -ansi -pedantic -o #{t.name} #{t.source}"
end

# Tasks
task :default => [:tests, :examples]

task :tests => [:clean, RESULT]

task :examples => EXAMPLES
