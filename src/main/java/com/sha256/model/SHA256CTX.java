package com.sha256.model;

public class SHA256CTX {
	 public long data[] = new long[64];
	    public int datalen;
	    public int bitlen;
	    public String word;
	    public long state[] = new long[8];
		

		
		public int getDatalen() {
			return datalen;
		}
		public void setDatalen(int datalen) {
			this.datalen = datalen;
		}
		public int getBitlen() {
			return bitlen;
		}
		public void setBitlen(int bitlen) {
			this.bitlen = bitlen;
		}
		public long[] getState() {
			return state;
		}
		public void setState(long[] state) {
			this.state = state;
		}
	    
	}

