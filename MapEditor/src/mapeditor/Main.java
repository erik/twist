/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mapeditor;

import java.awt.BorderLayout;
import java.awt.Dimension;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;

/**
 *
 * @author erik
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(17 * 64, 17 * 64);

        MapCanvas canvas = new MapCanvas(15, 15, "testmap");

        JScrollPane scroll = new JScrollPane(canvas);

        frame.add(scroll, BorderLayout.CENTER);
        //frame.pack();
        frame.setVisible(true);

    }
}
