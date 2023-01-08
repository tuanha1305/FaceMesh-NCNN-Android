package com.ufaceplus.facemesh.library

class NativeLib {

    /**
     * A native method that is implemented by the 'library' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    companion object {
        // Used to load the 'library' library on application startup.
        init {
            System.loadLibrary("library")
        }
    }
}