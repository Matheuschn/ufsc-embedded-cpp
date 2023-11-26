package com.example.digitalsafeapp

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import com.example.digitalsafeapp.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
        binding.sampleText.text = showHelloString()
    }

    /**
     * A native method that is implemented by the 'digitalsafeapp' native library,
     * which is packaged with this application.
     */
    external fun showHelloString(): String

    companion object {
        // Used to load the 'digitalsafeapp' library on application startup.
        init {
            System.loadLibrary("digitalsafeapp")
        }
    }
}