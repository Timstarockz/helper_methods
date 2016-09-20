//
//  helper_methods.swift
//
//  Created by Timothy Desir on 9/17/16.
//  Copyright © 2016 tim inc. All rights reserved.
//

import UIKit

class helper_methods: NSObject {

}


public extension DispatchQueue {
    private static var _tokenTracker = [String]()
    
    public class func once(executeToken: String, block:(Void) -> Void) {
        objc_sync_enter(self);
        defer { objc_sync_exit(self) }
        if _tokenTracker.contains(executeToken) {
            return
        }
        
        _tokenTracker.append(executeToken)
        block()
    }
}


public extension UIImage {

    func tint(color: UIColor) -> UIImage {
        let ciImage = CIImage(image: self)
        let filter = CIFilter(name: "CIMultiplyCompositing")
        
        let colorFilter = CIFilter(name: "CIConstantColorGenerator")
        let ciColor = CIColor(color: color)
        colorFilter?.setValue(ciColor, forKey: kCIInputColorKey)
        let colorImage = colorFilter?.outputImage
        
        filter?.setValue(colorImage, forKey: kCIInputImageKey)
        filter?.setValue(ciImage, forKey: kCIInputBackgroundImageKey)
        
        return UIImage(ciImage: filter!.outputImage!)
    }
}
