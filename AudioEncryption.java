/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package com.mycompany.is;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.security.Key;
import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;

public class AudioEncryption {
    public static void main(String[] args) {
        try {
            String key = "ThisIsASecretKey"; // 128 bit key
            File audioFile = new File("E:\\back\\Imagine_Dragons_-_Bones_Official_Lyric_Video (1).mp3");
            FileInputStream in = new FileInputStream(audioFile);
            FileOutputStream out = new FileOutputStream("C:\\Users\\HP\\Downloads\\Recording.mp3");

            // Creating the Key
            Key secretKey = new SecretKeySpec(key.getBytes(), "AES");

            // Creating the Cipher
            Cipher cipher = Cipher.getInstance("AES");

            // Initializing the Cipher in Encrypt mode
            cipher.init(Cipher.ENCRYPT_MODE, secretKey);

            byte[] input = new byte[(int)audioFile.length()];
            in.read(input);

            // Encrypting the data
            byte[] encryptedData = cipher.doFinal(input);

            // Writing the encrypted data to a file
            out.write(encryptedData);
            in.close();
            out.close();
            System.out.println("Audio Encrypted Successfully!!");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

