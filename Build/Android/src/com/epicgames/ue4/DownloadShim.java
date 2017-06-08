package com.epicgames.ue4;

import com.cube.infinitybollz.OBBDownloaderService;
import com.cube.infinitybollz.DownloaderActivity;


public class DownloadShim
{
	public static OBBDownloaderService DownloaderService;
	public static DownloaderActivity DownloadActivity;
	public static Class<DownloaderActivity> GetDownloaderType() { return DownloaderActivity.class; }
}

