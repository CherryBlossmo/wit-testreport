import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.util.Enumeration;
import java.util.List;
import java.util.ArrayList;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;


public class ZIP {
	public static boolean unZip(File zipFile, String descDir) {
	    boolean flag = false;
	    File pathFile = new File(descDir);
	    if(!pathFile.exists()){
	        pathFile.mkdirs();
	    }
	    ZipFile zip = null;
	    try {

	        zip = new ZipFile(zipFile, Charset.forName("gbk"));
	        for(Enumeration entries = zip.entries(); entries.hasMoreElements();){
	            ZipEntry entry = (ZipEntry)entries.nextElement();
	            String zipEntryName = entry.getName();
	            InputStream in = zip.getInputStream(entry);
	            String outPath = (descDir+zipEntryName).replace("/", File.separator);

	            File file = new File(outPath.substring(0, outPath.lastIndexOf(File.separator)));
	            if(!file.exists()){
	                file.mkdirs();
	            }
	            //判断文件全路径是否为文件夹,如果是上面已经上传,不需要解压
	            if(new File(outPath).isDirectory()){
	                continue;
	            }
	            //保存文件路径信息
	            //urlList.add(outPath);

	            OutputStream out = new FileOutputStream(outPath);
	            byte[] buf1 = new byte[2048];
	            int len;
	            while((len=in.read(buf1))>0){
	                out.write(buf1,0,len);
	            }
	            in.close();
	            out.close();
	        }
	        flag = true;

	        zip.close();
	    } catch (IOException e) {
	        e.printStackTrace();
	    }
	    return flag;
	}
}
