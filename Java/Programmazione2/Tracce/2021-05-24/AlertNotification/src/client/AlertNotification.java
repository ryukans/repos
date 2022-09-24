package client;

import java.io.Serializable;

public class AlertNotification implements Serializable
{
    private int componentId;
    private int criticality;

    public AlertNotification(int componentId, int criticality)
    {
        this.componentId = componentId;
        this.criticality = criticality;
    }

    public int getComponentId() {
        return componentId;
    }

    public void setComponentId(int componentId) {
        this.componentId = componentId;
    }

    public int getCriticality() {
        return criticality;
    }

    public void setCriticality(int criticality) {
        this.criticality = criticality;
    }

}
