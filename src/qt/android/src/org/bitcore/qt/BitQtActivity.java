package org.bitcore.qt;

import android.os.Bundle;
import android.system.ErrnoException;
import android.system.Os;

import org.qtproject.qt5.android.bindings.QtActivity;

import java.io.File;

public class BitQtActivity extends QtActivity
{
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        final File bitDir = new File(getFilesDir().getAbsolutePath() + "/.bit");
        if (!bitDir.exists()) {
            bitDir.mkdir();
        }

        super.onCreate(savedInstanceState);
    }
}
