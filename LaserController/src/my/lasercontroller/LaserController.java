/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package my.lasercontroller;

import gnu.io.SerialPort;
import java.io.OutputStream;
import gnu.io.CommPortIdentifier;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Enumeration;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.zu.ardulink.Link;
import org.zu.ardulink.gui.ConnectionPanel;
import org.zu.ardulink.gui.PWMController;

/**
 *
 * @author bernanos
 */
public class LaserController extends javax.swing.JFrame {
    
    // Global variables declaration
    SerialPort serialPort;
    private OutputStream output;
    private static final int TIME_OUT = 2000;
    private static final int DATA_RATE = 115200;

    /**
     * Creates new form LaserController
     */
    public LaserController() {
        initComponents();
        listPorts();
    }
    
    private void listPorts() {

            Enumeration portEnum = CommPortIdentifier.getPortIdentifiers();

            //First, Find an instance of serial port as set in PORT_NAMES.
            while (portEnum.hasMoreElements()) {
                    CommPortIdentifier currPortId = (CommPortIdentifier) portEnum.nextElement();
                    
                    portDropDown.addItem(currPortId.getName());
                    
            }

    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        laserPanel1 = new javax.swing.JPanel();
        enable1 = new javax.swing.JRadioButton();
        btnTest1 = new javax.swing.JToggleButton();
        freq1 = new javax.swing.JTextField();
        jLabel7 = new javax.swing.JLabel();
        duration1 = new javax.swing.JTextField();
        jLabel8 = new javax.swing.JLabel();
        btnCal1 = new javax.swing.JToggleButton();
        btnConnect = new javax.swing.JButton();
        portDropDown = new javax.swing.JComboBox<>();
        btnExec = new javax.swing.JButton();
        laserPanel2 = new javax.swing.JPanel();
        enable2 = new javax.swing.JRadioButton();
        btnTest2 = new javax.swing.JToggleButton();
        freq2 = new javax.swing.JTextField();
        jLabel9 = new javax.swing.JLabel();
        duration2 = new javax.swing.JTextField();
        jLabel10 = new javax.swing.JLabel();
        btnCal2 = new javax.swing.JToggleButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        laserPanel1.setBorder(javax.swing.BorderFactory.createTitledBorder("Laser 1"));

        enable1.setText("Enable");
        enable1.setEnabled(false);
        enable1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                enable1ActionPerformed(evt);
            }
        });

        btnTest1.setText("TEST");
        btnTest1.setEnabled(false);
        btnTest1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnTest1ActionPerformed(evt);
            }
        });

        freq1.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        freq1.setText("10");
        freq1.setEnabled(false);
        freq1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                freq1ActionPerformed(evt);
            }
        });

        jLabel7.setText("Freq");

        duration1.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        duration1.setText("10");
        duration1.setEnabled(false);
        duration1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                duration1ActionPerformed(evt);
            }
        });

        jLabel8.setText("Duration");

        btnCal1.setText("Calibrate");
        btnCal1.setEnabled(false);
        btnCal1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCal1ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout laserPanel1Layout = new javax.swing.GroupLayout(laserPanel1);
        laserPanel1.setLayout(laserPanel1Layout);
        laserPanel1Layout.setHorizontalGroup(
            laserPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(laserPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(laserPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(btnTest1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(laserPanel1Layout.createSequentialGroup()
                        .addGroup(laserPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(enable1)
                            .addGroup(laserPanel1Layout.createSequentialGroup()
                                .addGroup(laserPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(freq1, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(duration1, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(laserPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jLabel8)
                                    .addComponent(jLabel7))))
                        .addGap(0, 0, Short.MAX_VALUE))
                    .addComponent(btnCal1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap())
        );
        laserPanel1Layout.setVerticalGroup(
            laserPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(laserPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(enable1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(laserPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.CENTER)
                    .addComponent(freq1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel7))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(laserPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.CENTER)
                    .addComponent(duration1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel8))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(btnTest1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(btnCal1)
                .addContainerGap())
        );

        btnConnect.setText("Connect");
        btnConnect.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnConnectActionPerformed(evt);
            }
        });

        portDropDown.setMaximumRowCount(16);
        portDropDown.setToolTipText("");

        btnExec.setText("Execute");
        btnExec.setEnabled(false);
        btnExec.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnExecActionPerformed(evt);
            }
        });

        laserPanel2.setBorder(javax.swing.BorderFactory.createTitledBorder("Laser 2"));

        enable2.setText("Enable");
        enable2.setEnabled(false);
        enable2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                enable2ActionPerformed(evt);
            }
        });

        btnTest2.setText("TEST");
        btnTest2.setEnabled(false);
        btnTest2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnTest2ActionPerformed(evt);
            }
        });

        freq2.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        freq2.setText("10");
        freq2.setEnabled(false);
        freq2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                freq2ActionPerformed(evt);
            }
        });

        jLabel9.setText("Freq");

        duration2.setHorizontalAlignment(javax.swing.JTextField.CENTER);
        duration2.setText("10");
        duration2.setEnabled(false);
        duration2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                duration2ActionPerformed(evt);
            }
        });

        jLabel10.setText("Duration");

        btnCal2.setText("Calibrate");
        btnCal2.setEnabled(false);
        btnCal2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCal2ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout laserPanel2Layout = new javax.swing.GroupLayout(laserPanel2);
        laserPanel2.setLayout(laserPanel2Layout);
        laserPanel2Layout.setHorizontalGroup(
            laserPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(laserPanel2Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(laserPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(btnTest2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(laserPanel2Layout.createSequentialGroup()
                        .addGroup(laserPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(enable2)
                            .addGroup(laserPanel2Layout.createSequentialGroup()
                                .addGroup(laserPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(freq2, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(duration2, javax.swing.GroupLayout.PREFERRED_SIZE, 75, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(laserPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jLabel10)
                                    .addComponent(jLabel9))))
                        .addGap(0, 0, Short.MAX_VALUE))
                    .addComponent(btnCal2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap())
        );
        laserPanel2Layout.setVerticalGroup(
            laserPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(laserPanel2Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(enable2)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(laserPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.CENTER)
                    .addComponent(freq2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel9))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(laserPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.CENTER)
                    .addComponent(duration2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel10))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(btnTest2)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(btnCal2)
                .addContainerGap())
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(37, 37, 37)
                        .addComponent(portDropDown, javax.swing.GroupLayout.PREFERRED_SIZE, 286, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(btnExec)
                            .addComponent(btnConnect)))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(16, 16, 16)
                        .addComponent(laserPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(laserPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(130, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(19, 19, 19)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(laserPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(laserPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 197, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(portDropDown, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnConnect))
                .addGap(18, 18, 18)
                .addComponent(btnExec)
                .addGap(218, 218, 218))
        );

        laserPanel1.getAccessibleContext().setAccessibleName("Laser 2");

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btnConnectActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnConnectActionPerformed
        // TODO add your handling code here:
        
        if (btnConnect.getText().equals("Connect")) {
            // Get port and baud rate from connection panel
            CommPortIdentifier portId = null;
            Enumeration portEnum = CommPortIdentifier.getPortIdentifiers();

            String selectedPort = portDropDown.getSelectedItem().toString();

            while (portEnum.hasMoreElements()) {

                CommPortIdentifier currPortId = (CommPortIdentifier) portEnum.nextElement();
                if (currPortId.getName().equals(selectedPort)) {
                    portId = currPortId;
                    System.out.println("Port found...");
                    break;
                }
            }
            if (portId == null) {
                System.out.println("Could not find COM port.");
                return;
            }

            try {
                    // open serial port, and use class name for the appName.
                    //First, Find an instance of serial port as set in PORT_NAMES.

                    serialPort = (SerialPort) portId.open(this.getClass().getName(),
                                    TIME_OUT);

                    // set port parameters
                    serialPort.setSerialPortParams(DATA_RATE,
                                    SerialPort.DATABITS_8,
                                    SerialPort.STOPBITS_1,
                                    SerialPort.PARITY_NONE);

                    // open the streams
                    //input = new BufferedReader(new InputStreamReader(serialPort.getInputStream()));
                    output = new PrintStream(serialPort.getOutputStream(), true);

                    // add event listeners
                    //serialPort.addEventListener(this);
                    //serialPort.notifyOnDataAvailable(true);
                    System.out.println("Connected...");
                    btnConnect.setText("Disconnect");
                    btnExec.setEnabled(true);
                    enable1.setEnabled(true);
                    enable2.setEnabled(true);
                    /*
                    enable3.setEnabled(true);
                    enable4.setEnabled(true);
                    enable5.setEnabled(true);
                    enable6.setEnabled(true);
                    */

            } catch (Exception e) {
                System.out.println("Could not connect...");
                System.err.println(e.toString());
            }
        } else if (btnConnect.getText().equals("Disconnect")) {
            if (serialPort != null) {
                serialPort.removeEventListener();
                serialPort.close();
                System.out.println("Disonnected...");
                btnConnect.setText("Connect");
                btnExec.setEnabled(false);
                enable1.setEnabled(false);
                enable2.setEnabled(false);
                // Write code to disable all objects once disconnected
                
                /*
                enable3.setEnabled(true);
                enable4.setEnabled(true);
                enable5.setEnabled(true);
                enable6.setEnabled(true);
                */
            }
        }
    }//GEN-LAST:event_btnConnectActionPerformed

    private void btnExecActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnExecActionPerformed
        // TODO add your handling code here:
        if(btnExec.getText() == "Execute") {
            String message = "E,";
            sendData(message);
            btnExec.setText("Stop");
        } else {
            String message = "O,";
            sendData(message);
            btnExec.setText("Execute");
        }
    }//GEN-LAST:event_btnExecActionPerformed

    private void duration1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_duration1ActionPerformed
        // TODO add your handling code here:
        if (btnTest1.isSelected()){
            int dur = Integer.parseInt(duration1.getText());
            int freq = Integer.parseInt(freq1.getText());
            String message = String.format("T,%d,%d,%d,%d,", 1, 1, dur, freq);
            sendData(message);
        }
    }//GEN-LAST:event_duration1ActionPerformed

    private void btnTest1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnTest1ActionPerformed
        // TODO add your handling code here:
        if (btnTest1.isSelected()){
            System.out.println("Laser1 ON");
            // Sent message to arduino to switch laser 1 ON
            int dur = Integer.parseInt(duration1.getText());
            int freq = Integer.parseInt(freq1.getText());
            String message = String.format("T,%d,%d,%d,%d,", 1, 1, dur, freq);
            sendData(message);
        } else {
            System.out.println("Laser1 OFF");
            // Send message to arduino to swich laser 1 OFF
            String message = "T,1,0,0,0,";
            sendData(message);
        }
    }//GEN-LAST:event_btnTest1ActionPerformed

    private void enable1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_enable1ActionPerformed
        // TODO add your handling code here:
        if (enable1.isSelected()) {
            btnTest1.setEnabled(true);
            freq1.setEnabled(true);
            duration1.setEnabled(true);
            btnCal1.setEnabled(true);
        } else {
            btnTest1.setEnabled(false);
            freq1.setEnabled(false);
            duration1.setEnabled(false);
            btnCal1.setEnabled(false);
        }
    }//GEN-LAST:event_enable1ActionPerformed

    private void freq1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_freq1ActionPerformed
        // TODO add your handling code here:
        if (btnTest1.isSelected()){
            int dur = Integer.parseInt(duration1.getText());
            int freq = Integer.parseInt(freq1.getText());
            String message = String.format("T,%d,%d,%d,%d,", 1, 1, dur, freq);
            sendData(message);
        }
    }//GEN-LAST:event_freq1ActionPerformed

    private void btnCal1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCal1ActionPerformed
        // TODO add your handling code here:
        if (btnCal1.isSelected()){
            String message = "C,1,1,";
            sendData(message);
        } else {
            String message = "C,1,0,";
            sendData(message);
        }
    }//GEN-LAST:event_btnCal1ActionPerformed

    private void enable2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_enable2ActionPerformed
        // TODO add your handling code here:
        if (enable2.isSelected()) {
            btnTest2.setEnabled(true);
            freq2.setEnabled(true);
            duration2.setEnabled(true);
            btnCal2.setEnabled(true);
        } else {
            btnTest2.setEnabled(false);
            freq2.setEnabled(false);
            duration2.setEnabled(false);
            btnCal2.setEnabled(false);
        }
    }//GEN-LAST:event_enable2ActionPerformed

    private void btnTest2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnTest2ActionPerformed
        // TODO add your handling code here:
        if (btnTest2.isSelected()){
            System.out.println("Laser2 ON");
            // Sent message to arduino to switch laser 1 ON
            int dur = Integer.parseInt(duration2.getText());
            int freq = Integer.parseInt(freq2.getText());
            String message = String.format("T,%d,%d,%d,%d,", 2, 1, dur, freq);
            sendData(message);
        } else {
            System.out.println("Laser2 OFF");
            // Send message to arduino to swich laser 1 OFF
            String message = "T,2,0,0,0,";
            sendData(message);
        }
    }//GEN-LAST:event_btnTest2ActionPerformed

    private void freq2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_freq2ActionPerformed
        // TODO add your handling code here:
        if (btnTest2.isSelected()){
            int dur = Integer.parseInt(duration2.getText());
            int freq = Integer.parseInt(freq2.getText());
            String message = String.format("T,%d,%d,%d,%d,", 2, 1, dur, freq);
            sendData(message);
        }
    }//GEN-LAST:event_freq2ActionPerformed

    private void duration2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_duration2ActionPerformed
        // TODO add your handling code here:
        if (btnTest2.isSelected()){
            int dur = Integer.parseInt(duration2.getText());
            int freq = Integer.parseInt(freq2.getText());
            String message = String.format("T,%d,%d,%d,%d,", 2, 1, dur, freq);
            sendData(message);
        }
    }//GEN-LAST:event_duration2ActionPerformed

    private void btnCal2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCal2ActionPerformed
        // TODO add your handling code here:
        if (btnCal2.isSelected()){
            String message = "C,2,1,";
            sendData(message);
        } else {
            String message = "C,2,0,";
            sendData(message);
        }
    }//GEN-LAST:event_btnCal2ActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(LaserController.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(LaserController.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(LaserController.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(LaserController.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                new LaserController().setVisible(true);
            }
        });
    }
    
    public void setupSystemp(){
        /**
         * Will iterate through each laser and send respective parameters
         * including the paradigm for each channel.
         * Should receive a confirmation from Arduino
         */
    }
    
    public void sendData(String message){
        if(output != null){
            try {
                // Add code to send data
                System.out.println(message);
                output.write(message.getBytes());
                //output.flush();
            } catch (IOException ex) {
                System.out.println("Could not send message...");
                Logger.getLogger(LaserController.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JToggleButton btnCal1;
    private javax.swing.JToggleButton btnCal2;
    private javax.swing.JButton btnConnect;
    private javax.swing.JButton btnExec;
    private javax.swing.JToggleButton btnTest1;
    private javax.swing.JToggleButton btnTest2;
    private javax.swing.JTextField duration1;
    private javax.swing.JTextField duration2;
    private javax.swing.JRadioButton enable1;
    private javax.swing.JRadioButton enable2;
    private javax.swing.JTextField freq1;
    private javax.swing.JTextField freq2;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JPanel laserPanel1;
    private javax.swing.JPanel laserPanel2;
    private javax.swing.JComboBox<String> portDropDown;
    // End of variables declaration//GEN-END:variables
}
