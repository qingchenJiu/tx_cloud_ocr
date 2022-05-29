
Pod::Spec.new do |s|
  s.name             = 'WBOCRService'
  s.version          = '4.8.0'    
  s.summary          = 'A short description of WBHJOCRService.'
  s.description      = "ocr sdk."
  s.homepage         = 'xxx'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'xx' => 'xxx' }
  s.source           = { :path => '.' }
  
  s.ios.deployment_target = '8.0'
  s.library = 'c++'
  s.frameworks = "CoreTelephony", "CoreServices", "CoreMedia", "AssetsLibrary","AVFoundation","WebKit","SystemConfiguration"
  
  s.resource_bundles = {
    'WBOCRService' => ['Libs/WBOCRService.bundle/*.png']
  }
  
  s.subspec 'BinaryLib' do |lib|
    # lib.vendored_libraries = "Libs/*.a"
    lib.vendored_frameworks = "Libs/*.framework"
  end
  
 
end
