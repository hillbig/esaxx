VERSION= '0.0.5'
APPNAME= 'esaxx'

srcdir= '.'
blddir= 'bin'

def options(opt):
  opt.load('compiler_cxx')
  opt.load('unittest_gtest')

def configure(conf):
  conf.env.CXXFLAGS += ['-O2', '-Wall', '-g']
  conf.load('compiler_cxx')
  conf.load('unittest_gtest')

def build(bld):
  bld.program(
    source = 'enumSubstring.cpp',
    target = 'enumSubstring'
  )

  bld.program(
    features = 'gtest',
    source = 'esaTest.cpp',
    target = 'esaTest'
  )

def dist_hook():
  import os
  os.remove('upload.sh')
  os.remove('googlecode_upload.py')
