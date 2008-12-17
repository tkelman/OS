/**
 * @(#)EntityData 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osentity;

/**
*
* <p>A data structure class that corresponds to an xml element in the OSeL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
public class EntityData {

	public GeneralInfo general = null;
	
	public SystemInfo system = null;
	
	public ServiceInfo service = null;
	
	public JobInfo job = null;
	
	public OptimizationInfo optimization = null;
	
	public OtherEntityInfo[] other = null;
	
}//EntityData