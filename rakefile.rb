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
  sh "g++ -ansi -o #{t.name} #{t.source}"
end

# Tasks
task :default => [:tests, :examples]

task :tests => RESULT

task :examples => EXAMPLES
