package com.sha256;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.SwingUtilities;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.builder.SpringApplicationBuilder;

import com.sha256.gui.SHA256GUI;

@SpringBootApplication
public class Sha256GuiApplication extends JFrame{
	public Sha256GuiApplication() {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				new SHA256GUI().setVisible(true);
			}
		});
	}
	public static void main(String[] args) {
		var ctx = new SpringApplicationBuilder(Sha256GuiApplication.class).headless(false).run(args);

		EventQueue.invokeLater(() -> {

			var ex = ctx.getBean(Sha256GuiApplication.class);
			ex.setVisible(true);
		});
	}
}