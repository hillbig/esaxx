VERSION= '0.0.5'
APPNAME= 'esaxx'

srcdir= '.'
blddir= 'bin'

def options(opt):
  opt.load('compiler_cxx')

def configure(conf):
  conf.env.CXXFLAGS += ['-O2', '-Wall', '-g']
  conf.load('compiler_cxx')

def build(bld):
  bld.program(
    source = 'enumSubstring.cpp',
    target = 'enumSubstring'
  )

def dist_hook():
  import os
  os.remove('upload.sh')
  os.remove('googlecode_upload.py')
